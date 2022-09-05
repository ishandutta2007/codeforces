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

const int md = 998244353;
const ull P = 1ull * md * md;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 105;

struct mat { int a[N][N]; } E, DEG, V1, F0, F1;

vector <int> adj[N];
int n, m, k, ans;

mat operator + (const mat a, const mat b) {
    mat ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans.a[i][j] = add(a.a[i][j], b.a[i][j]);
        }
    }
    return ans;
}

mat operator * (const mat a, const mat b) {
    mat ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ull sum = 0;
            for (int k = 1; k <= n; k++) {
                sum += 1ll * a.a[i][k] * b.a[k][j];
                if (sum >= P) sum -= P;
            }
            ans.a[i][j] = sum % md;
        }
    }
    return ans;
}

struct mat2 { mat a[2][2]; } A, B;

mat2 operator * (const mat2 a, const mat2 b) {
    mat2 ans;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            ans.a[i][j] = (a.a[i][0] * b.a[0][j] + a.a[i][1] * b.a[1][j]);
        }
    }
    return ans;
}

int main() {
    read(n); read(m); read(k);
    if (k <= 2) {
        print(0, '\n');
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++E.a[u][v]; ++E.a[v][u];
    }
    for (int i = 1; i <= n; i++) {
        V1.a[i][i] = 1;
        DEG.a[i][i] = sub(0, (int)adj[i].size());
    }
    A.a[0][0] = E; A.a[0][1] = V1; A.a[1][0] = DEG + V1; B = A;
    int need = k - 2;
    while (need) {
        if (need & 1) B = B * A;
        need >>= 1; A = A * A;
    }
    F0 = E; F1 = DEG;
    mat res = B.a[0][0] * F0 + B.a[0][1] * F1;
    for (int i = 1; i <= n; i++) ans = add(ans, res.a[i][i]);
    print(ans, '\n');
    return 0;
}