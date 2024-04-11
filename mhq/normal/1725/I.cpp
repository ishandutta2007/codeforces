#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

//int inv(int x) {
//    return bp(x, mod - 2);
//}

int n;
const int maxN = 1e5 + 10;
vector<int> g[maxN];
int p[maxN];
int sz[maxN];
int get(int x) {
    if (x == p[x]) return x;
    p[x] = get(p[x]);
    return p[x];
}
void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
}
const int maxK = 2e5 + 10;
int fact[maxK], invfact[maxK], inv[maxK];
int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
void solve() {
    fact[0] = invfact[0] = invfact[1] = inv[1] = fact[1] = 1;
    for (int i = 2; i < maxK; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    int coef = 1;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u = get(u);
        v = get(v);
        int C = mult(sz[u], sz[v]);
        coef = mult(coef, C);
        coef = mult(coef, C);
//        int edges = 2 * (sz[u] + sz[v]) - 2;
//        edges -= 1;
//        coef = mult(coef, cnk(edges, 2 * sz[u] - 2));
//        coef = mult(coef, cnk(edges - (2 * sz[u] - 2), 2 * sz[v] - 2));
//        coef = mult(coef, 2 * (sz[u] + sz[v]) - 3);
        unite(u, v);
    }
    for (int i = 1; i <= 2 * n - 3; i += 2) {
        coef = mult(coef, i);
    }
    cout << coef << '\n';
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}