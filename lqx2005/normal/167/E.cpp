#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int N = 600 + 10;
int P;
struct mint {
    int x;
    mint() {x = 0; }
    mint(int _x) {x = _x; }
    friend mint operator + (const mint a, const mint b) {return (a.x + b.x) % P; }
    friend mint operator - (const mint a, const mint b) {return (a.x - b.x + P) % P; }
    friend mint operator * (const mint a, const mint b) {return 1ll * a.x * b.x % P; }
    friend mint operator ^ (mint a, int b) {
        mint c(1);
        for(; b; b >>= 1, a = a * a) if(b & 1) c = c * a;
        return c;
    }
    friend mint operator / (mint a, mint b) {return a * (b ^ (P - 2)); }
    friend mint &operator += (mint &a, const mint b) {return a = a + b; }
    friend mint &operator -= (mint &a, const mint b) {return a = a - b; }
    friend mint &operator *= (mint &a, const mint b) {return a = a * b; }
    friend mint &operator /= (mint &a, const mint b) {return a = a / b; }
} fac[N], ifac[N], inv[N];
void initmath(int n) {
    inv[1] = fac[0] = ifac[0] = 1;
    for(int i = 2; i <= n; i++) inv[i] = inv[P % i] * (P - P / i);
    for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * inv[i];
    return;
}
mint binom(int n, int m) {return n < m || m < 0 ? 0 : fac[n] * ifac[m] * ifac[n - m]; }
struct Matrix {
    mint a[N][N];
    mint det(int n) {
        mint prod = 1;
        for(int i = 1; i <= n; i++) {
            int p = -1;
            for(int j = i; j <= n; j++) {
                if(a[j][i].x) {
                    p = j;
                    break;
                }
            }
            if(p == -1) return 0;
            if(p != i) swap(a[p], a[i]), prod = 0 - prod;
            prod = prod * a[i][i];
            for(int j = i + 1; j <= n; j++) {
                mint coef = a[j][i] / a[i][i];
                for(int k = i; k <= n; k++) a[j][k] -= coef * a[i][k];
            }
        }
        return prod;
    }
}calc;
int n, m, deg[N];
vector<int> g[N];
mint cnt[N][N];
int in[N], out[N], toti = 0, toto = 0;
void topsort() {
    for(int i = 1; i <= toti; i++) cnt[in[i]][in[i]] = 1;
    deque<int> q;
    for(int i = 1; i <= toti; i++) q.eb(in[i]);
    while(!q.empty()) {
        int u = q.front();
        q.pop_front();
        for(int v : g[u]) {
            for(int i = 1; i <= n; i++) {
                cnt[i][v] += cnt[i][u];
            }
            deg[v]--;
            if(deg[v] == 0) q.eb(v);
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> P;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), deg[v]++;
    }
    for(int i = 1; i <= n; i++) if(deg[i] == 0) in[++toti] = i;
    for(int i = 1; i <= n; i++) if(g[i].empty()) out[++toto] = i;
    topsort();
    for(int i = 1; i <= toti; i++) {
        for(int j = 1; j <= toto; j++) {
            calc.a[i][j] = cnt[in[i]][out[j]];
        }
    }
    cout << calc.det(toti).x << endl;
    return 0;
}