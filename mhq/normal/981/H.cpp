#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int n, k;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1<<20;


void fft (vector<int> & a, bool invert) {
    int n = (int) a.size();

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        int wlen = invert ? root_1 : root;
        for (int i=len; i<root_pw; i<<=1)
            wlen = int (wlen * 1ll * wlen % mod);
        for (int i=0; i<n; i+=len) {
            int w = 1;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
                a[i+j] = u+v < mod ? u+v : u+v-mod;
                a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
                w = int (w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = pw(n, mod - 2);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % mod);
    }
}
void poly_mult(vector < int >& a, vector < int > b) {
    int s = a.size() + b.size();
    int r = 1;
    while (r < s) r *= 2;
    a.resize(r);
    b.resize(r);
    fft(a, false);
    fft(b, false);
    for (int j = 0; j < r; j++) {
        a[j] = mult(a[j], b[j]);
    }
    fft(a, true);
    while (!a.empty() && (a.back() == 0)) a.pop_back();
}
vector < int > g[maxN];
int sz[maxN];
int calc_batya[maxN];
int val[maxN];

int fact[maxN], invfact[maxN], inv[maxN];

void init() {
    inv[1] = invfact[1] = invfact[0] = fact[0] = fact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
}

vector < int > go(int l, int r, vector < int >& all) {
    if (l == r) {
        vector < int > f(2);
        f[0] = 1;
        f[1] = all[l];
        return f;
    }
    else {
        int mid = (l + r) / 2;
        auto it1 = go(l, mid, all);
        auto it2 = go(mid + 1, r, all);
        poly_mult(it1, it2);
        return it1;
    }
}

int cnk(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}


void dfs(int v, int p) {
    sz[v] = 1;
    vector < int > sizes;
    vector < pair < int, int > > bySz;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
        sizes.push_back(sz[to]);
        bySz.emplace_back(sz[to], to);
    }
    vector < int > tot;
    if (!sizes.empty()) tot = go(0, sizes.size() - 1, sizes);
    else tot = vector < int >(1, 1);
    for (int i = 0; i < tot.size() && i <= k; i++) {
        val[v] = sum(val[v], mult(fact[i], mult(tot[i], cnk(k, i))));
    }
    sort(bySz.begin(), bySz.end());
    int coef = n - sz[v];
    vector < int > ntot(tot.size() + 1);
    for (int i = 0; i < tot.size(); i++) {
        ntot[i] = sum(ntot[i], tot[i]);
        ntot[i + 1] = sum(ntot[i + 1], mult(tot[i], coef));
    }
    for (int i = 0; i < bySz.size(); i++) {
        if (i > 0 && bySz[i].first == bySz[i - 1].first) {
            calc_batya[bySz[i].second] = calc_batya[bySz[i - 1].second];

        }
        else {
            vector < int > rl_back(tot.size());
            rl_back[0] = ntot[0];
            int his_coef = bySz[i].first;
            for (int j = 1; j < tot.size(); j++) {
                rl_back[j] = sub(ntot[j], mult(rl_back[j - 1], his_coef));
            }
            int bt = 0;
            for (int q = 0; q < tot.size() && q <= k; q++) {
                bt = sum(bt, mult(fact[q], mult(rl_back[q], cnk(k, q))));
            }
            calc_batya[bySz[i].second] = bt;
        }
    }
}
int ans = 0;
int in_sub[maxN];
void dfs_solve(int v, int p) {
    //cout << v << " " << val[v] << " " << calc_batya[v] << endl;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs_solve(to, v);
        ans = sum(ans, mult(in_sub[v], in_sub[to]));
        in_sub[v] = sum(in_sub[v], in_sub[to]);
    }
    in_sub[v] = sum(in_sub[v], val[v]);
    ans = sum(ans, mult(calc_batya[v], in_sub[v]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    init();
    cin >> n >> k;
    if (k == 1) {
        cout << mult(mult(n, n - 1), inv[2]);
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    dfs_solve(1, -1);
    cout << ans;
    return 0;
}