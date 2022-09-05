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

const int N = 1e5 + 5;
const long double eps = 1e-12;
const long double PI = acos(-1.0);

struct ele {
    long double pos;
    int id, opt;
    ele (long double x = 0, int y = 0, int z = 0) : pos(x), id(y), opt(z) {}
} a[N * 6];

bool operator < (const ele a, const ele b) {
    if (fabs(a.pos - b.pos) <= eps) return a.id < b.id;
    return a.pos < b.pos;
}

int x[N], y[N], las[N], used[N];
int n; ll k;

long double dis(int x, int y) { return sqrt(x * x + y * y); }

struct fenwick {
    int f[N * 6], n;

    void add(int x, int y) {
        while (x <= n) {
            f[x] += y;
            x += (x & -x);
        }
    }

    int query(int x) {
        int ans = 0;
        while (x) {
            ans += f[x];
            x &= (x - 1);
        }
        return ans;
    }
} tr;

bool check(long double r) {
    int cnt = 0, len = 0;
    for (int i = 1; i <= n; i++) {
        long double nowdis = dis(x[i], y[i]);
        if (nowdis > r + eps) {
            long double ang = atan2(y[i], x[i]);
            long double ang2 = acos(r / nowdis);
            long double l = ang - ang2, r = ang + ang2;
            if (l < -eps) l += PI * 2, r += PI * 2;
            if (l - eps >= PI * 2) l -= PI * 2, r -= PI * 2;
            a[++len] = ele(l, i, 0); a[++len] = ele(r, i, 1);
            if (r <= PI * 2) {
                a[++len] = ele(l + PI * 2, i, 2);
                a[++len] = ele(r + PI * 2, i, 3);
                a[++len] = ele(l + PI * 4, i, 2);
                a[++len] = ele(r - PI * 2, i, 3);
            } else {
                a[++len] = ele(l - PI * 2, i, 2);
                a[++len] = ele(r - PI * 2, i, 3);
                a[++len] = ele(l + PI * 2, i, 2);
                a[++len] = ele(r + PI * 2, i, 3);
            }
        } else ++cnt;
    }
    ll ans0 = 0, ans = 0, ans2 = 0;
    for (int i = 1; i <= cnt; i++) ans0 += (n - i);
    sort(a + 1, a + len + 1);
    memset(tr.f, 0, sizeof(tr.f)); tr.n = len;
    memset(used, 0, sizeof(used));
    memset(las, 0, sizeof(las));
    for (int i = 1; i <= len; i++) {
        // fprintf(stderr, "r = %.12lf, pos = %.12lf, id = %d, opt = %d\n", (double)r, (double)a[i].pos, a[i].id, a[i].opt);
        if (a[i].opt == 0) {
            las[a[i].id] = i;
        } else if (a[i].opt == 1) {
            if (!las[a[i].id]) continue;
            int in = tr.query(i) - tr.query(las[a[i].id]);
            if (!used[a[i].id]) ans += in;
            int not_in = n - cnt - 1 - (i - 1 - las[a[i].id] - in);
            if (!used[a[i].id]) ans2 += not_in;
            // fprintf(stderr, "in = %d, not_in = %d\n", in, not_in);
            used[a[i].id] = 1;
            tr.add(las[a[i].id], 1);
            las[a[i].id] = 0;
            // fprintf(stderr, "las[a[i].id] = %d\n", las[a[i].id]);
        } else if (a[i].opt == 2) {
            las[a[i].id] = i;
        } else {
            if (!las[a[i].id]) continue;
            tr.add(las[a[i].id], 1);
            las[a[i].id] = 0;
        }
    }
    // cout << "ans2 = " << ans2 << endl;
    // assert((ans2 - ans) % 2 == 0);
    return ans0 + ans + (ans2 - ans) / 2 >= k;
}

int main() {
    // freopen("input.txt", "r", stdin);
    read(n); read(k);
    for (int i = 1; i <= n; i++) {
        read(x[i]); read(y[i]);
    }
    long double l = 0, r = 20000;
    while (r - l > 1e-8) {
        long double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    printf("%.10lf\n", (double)l);
    return 0;
}