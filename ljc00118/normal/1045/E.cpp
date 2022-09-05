#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

struct point_t {
    int x, y, col, id;
    point_t (int k1 = 0, int k2 = 0, int k3 = 0, int k4 = 0) : x(k1), y(k2), col(k3), id(k4) {}
    bool operator < (const point_t A) const {
        if (x != A.x) return x < A.x;
        return y < A.y;
    }
};

point_t operator - (const point_t a, const point_t b) {
    return point_t(a.x - b.x, a.y - b.y);
}

ll cross(point_t a, point_t b) {
    return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

vector <point_t> make_hull(vector <point_t> a) {
    int n = (int)a.size();
    sort(a.begin(), a.end());
    vector <point_t> ans;
    int top = -1;
    for (int i = 0; i < n; i++) {
        while (top >= 1 && cross(a[i] - ans[top], a[i] - ans[top - 1]) > 0) ans.pop_back(), --top;
        ans.push_back(a[i]); ++top;
    }
    int lim = top + 1;
    for (int i = n - 2; i >= 0; i--) {
        while (top >= lim && cross(a[i] - ans[top], a[i] - ans[top - 1]) > 0) ans.pop_back(), --top;
        ans.push_back(a[i]); ++top;
    }
    ans.pop_back();
    return ans;
}

const double PI = acos(-1.0);

bool check(point_t a, point_t b, point_t c) {
    double ang1 = atan2(a.y, a.x), ang2 = atan2(b.y, b.x), ang3 = atan2(c.y, c.x);
    if (ang2 < ang1) ang2 += PI * 2;
    if (ang3 < ang1) ang3 += PI * 2;
    return ang3 <= ang2;
}

vector <pii> ans;

void solve(vector <point_t> a, vector <point_t> b, int col) {
    int id = -1;
    for (int i = 0; i < (int)b.size(); i++) {
        if (b[i].col == col) {
            id = i;
            break;
        }
    }
    if (id == -1) {
        for (int i = 0; i < (int)b.size(); i++) {
            ans.push_back(make_pair(a[0].id, b[i].id));
        }
        return;
    }
    ans.push_back(make_pair(a[2].id, b[id].id));
    vector <point_t> po[3];
    for (int i = 0; i < (int)b.size(); i++) {
        if (i == id) continue;
        for (int j = 0; j < 3; j++) {
            int go = (j + 1) % 3;
            if (check(a[go] - b[id], a[j] - b[id], b[i] - b[id])) {
                po[j].push_back(b[i]);
            }
        }
    }
    vector <point_t> tmp;
    tmp.clear(); tmp.push_back(a[0]); tmp.push_back(a[1]); tmp.push_back(b[id]);
    solve(tmp, po[0], col);
    tmp.clear(); tmp.push_back(a[2]); tmp.push_back(b[id]); tmp.push_back(a[1]);
    solve(tmp, po[1], col ^ 1);
    tmp.clear(); tmp.push_back(b[id]); tmp.push_back(a[2]); tmp.push_back(a[0]);
    solve(tmp, po[2], col ^ 1);
}

vector <point_t> a, b;
int vis[1005];
int n;

int main() {
    read(n); a.resize(n);
    for (int i = 0; i < n; i++) {
        read(a[i].x); read(a[i].y); read(a[i].col);
        a[i].id = i;
    }
    int cando = 1;
    for (int i = 1; i < n; i++) {
        if (a[i].col != a[0].col) {
            cando = 0;
            break;
        }
    }
    if (cando) {
        printf("%d\n", n - 1);
        for (int i = 1; i < n; i++) printf("%d %d\n", 0, i);
        return 0;
    }
    b = make_hull(a);
    int cnt = 0;
    for (int l = 0, r; l < (int)b.size(); l = r + 1) {
        r = l;
        while (r + 1 < (int)b.size() && b[l].col == b[r + 1].col) ++r;
        ++cnt;
    }
    if (cnt > 3) {
        printf("Impossible\n");
        return 0;
    }
    for (int i = 0; i < (int)b.size(); i++) vis[b[i].id] = 1;
    if (cnt == 1) {
        int id = -1;
        for (int i = 0; i < n; i++) {
            if (a[i].col != b[0].col) {
                id = i;
                break;
            }
        }
        for (int i = 1; i < (int)b.size(); i++) ans.push_back(make_pair(b[i - 1].id, b[i].id));
        vector < vector <point_t> > po(b.size());
        for (int i = 0; i < n; i++) {
            if (vis[i] || i == id) continue;
            for (int j = 0; j < (int)b.size(); j++) {
                int go = (j + 1) % b.size();
                if (check(b[j] - a[id], b[go] - a[id], a[i] - a[id])) {
                    po[j].push_back(a[i]);
                    break;
                }
            }
        }
        for (int i = 0; i < (int)b.size(); i++) {
            vector <point_t> tmp;
            tmp.push_back(b[(i + 1) % b.size()]);
            tmp.push_back(b[i]);
            tmp.push_back(a[id]);
            solve(tmp, po[i], a[id].col);
        }
    } else {
        reverse(b.begin(), b.end());
        // for (int i = 0; i < (int)b.size(); i++) {
        //     fprintf(stderr, "%d %d %d %d\n", b[i].x, b[i].y, b[i].col, b[i].id);
        // }
        int fir1 = -1;
        for (int i = 0; i < (int)b.size(); i++) {
            if (b[i].col != b[0].col) {
                fir1 = i;
                break;
            }
        }
        assert(fir1 != -1);
        int fir2 = fir1;
        while (b[fir2].col == b[fir1].col) fir2 = (fir2 + 1) % b.size();
        int now1 = fir1, now2 = fir2;
        while ((now1 + 1) % (int)b.size() != fir2) {
            vector <point_t> po;
            int go = (now1 + 1) % b.size();
            for (int i = 0; i < n; i++) {
                if (vis[i]) continue;
                if (check(b[go] - b[fir2], b[now1] - b[fir2], a[i] - b[fir2])) po.push_back(a[i]); //, fprintf(stderr, "now1 = %d, i = %d\n", now1, i);
            }
            vector <point_t> tmp;
            tmp.push_back(b[now1]);
            tmp.push_back(b[go]);
            tmp.push_back(b[fir2]);
            ans.push_back(make_pair(b[now1].id, b[go].id));
            solve(tmp, po, b[fir2].col);
            now1 = go;
            // fprintf(stderr, "now1 = %d, ans.size() = %d\n", now1, (int)ans.size());
        }
        while ((now2 + 1) % (int)b.size() != fir1) {
            vector <point_t> po;
            int go = (now2 + 1) % b.size();
            for (int i = 0; i < n; i++) {
                if (vis[i]) continue;
                if (check(b[go] - b[fir1],b[now2] - b[fir1], a[i] - b[fir1])) po.push_back(a[i]); //, fprintf(stderr, "now2 = %d, i = %d\n", now2, i);
            }
            vector <point_t> tmp;
            tmp.push_back(b[now2]);
            tmp.push_back(b[go]);
            tmp.push_back(b[fir1]);
            ans.push_back(make_pair(b[now2].id, b[go].id));
            solve(tmp, po, b[fir1].col);
            now2 = go;
            // fprintf(stderr, "now2 = %d, ans.size() = %d\n", now2, (int)ans.size());
        }
        // fprintf(stderr, "ans.size() = %d\n", (int)ans.size());
    }
    assert((int)ans.size() == n - 2);
    printf("%d\n", n - 2);
    for (int i = 0; i < n - 2; i++) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}