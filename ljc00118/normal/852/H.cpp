#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const double PI = acos(-1.0);
const int N = 205;

struct vec {
    int x, y;
    vec (int a = 0, int b = 0) : x(a), y(b) {}
};

vec operator + (vec a, vec b) {
    return vec(a.x + b.x, a.y + b.y);
}

vec operator - (vec a, vec b) {
    return vec(a.x - b.x, a.y - b.y);
}

ll cross(vec a, vec b) {
    return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

struct atom {
    vec val; int x, y;
} v[N * N];

ll f[N][55], ans;
int id[N], cnt[N][N], pre[N];
vec a[N];
int n, k, len;

int calc(int i, int j, int k) {
    if (i > j) swap(i, j);
    if (i > k) swap(i, k);
    if (j > k) swap(j, k);
    int ans = abs(cnt[i][k] - cnt[i][j] - cnt[j][k]);
    if (cross(a[j] - a[i], a[k] - a[i]) > 0) --ans;
    return ans;
}

double fix(double ang) {
    if (ang < 0) ang += 2 * PI;
    if (ang > 2 * PI) ang -= 2 * PI;
    return ang;
}

bool cmp1(vec a, vec b) {
    return a.x < b.x;
}

int S;
bool cmp2(int i, int j) {
    vec x = a[i] - a[S], y = a[j] - a[S];
    return fix(atan2(x.y, x.x)) < fix(atan2(y.y, y.x));
}

bool cmp3(atom a, atom b) {
    double ang1 = fix(atan2(a.val.y, a.val.x));
    double ang2 = fix(atan2(b.val.y, b.val.x));
    if (fabs(ang1 - ang2) < 1e-8) return 0;
    return ang1 < ang2;
}

int main() {
    read(n); read(k);
    for (int i = 1; i <= n; i++) read(a[i].x), read(a[i].y);
    sort(a + 1, a + n + 1, cmp1);
    // for (int i = 1; i <= n; i++) fprintf(stderr, "%d %d\n", a[i].x, a[i].y);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = i + 1; k <= j - 1; k++) {
                cnt[i][j] += (cross(a[k] - a[i], a[j] - a[i]) > 0);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            ++len; v[len].val = a[j] - a[i]; v[len].x = i; v[len].y = j;
        }
    }
    sort(v + 1, v + len + 1, cmp3);
    for (int s = 1; s <= n; s++) {
        memset(f, -1, sizeof(f));
        S = s;
        int m = 1;
        for (int i = 1; i <= n; i++) {
            if (i != s) {
                id[++m] = i;
            }
        }
        id[1] = s; sort(id + 2, id + n + 1, cmp2);
        for (int i = 1; i <= n; i++) pre[id[i]] = i;
        f[s][1] = 0;
        for (int i = 1; i <= len; i++) {
            if (v[i].y != s && pre[v[i].x] < pre[v[i].y] && calc(s, v[i].x, v[i].y) == 0) {
                int x = v[i].x, y = v[i].y; ll val = abs(cross(a[x] - a[s], a[y] - a[s]));
                for (int j = 1; j < k; j++) {
                        // fprintf(stderr, "s = %d, x = %d, y = %d, j = %d\n", s, x, y, j);
                    if (f[x][j] != -1) {
                        f[y][j + 1] = max(f[y][j + 1], f[x][j] + val);
                    }
                }
            }
            if (v[i].y == s) ans = max(ans, f[v[i].x][k]);
        }
    }
    print(ans / 2);
    if (ans % 2 == 1) printf(".50\n");
    else printf(".00\n");
    return 0;
}