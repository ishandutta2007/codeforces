#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1<<20;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

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

int n;
const int maxN = 25 * 10000 + 10;
vector<int> g[maxN];
vector<pair<int,int>> all;
void dfs(int v, int p) {
    int c = 0;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        c++;
    }
    all.emplace_back(1, c);
}
vector<int> do_mult(int l, int r, vector<pair<int,int>>& t) {
    if (l == r) {
        return {t[l].first, t[l].second};
    }
    int mid = (l + r) / 2;
    auto c1 = do_mult(l, mid, t);
    auto c2 = do_mult(mid + 1, r, t);
    poly_mult(c1, c2);
    while (c1.back() == 0) c1.pop_back();
    return c1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1, -1);
    auto res = do_mult(0, all.size() - 1, all);
    int ans = 0;
    vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = mult(i, fact[i - 1]);
    for (int z = 0; z < res.size(); z++) {
        if (z % 2 == 0) ans = sum(ans, mult(fact[n - z], res[z]));
        else ans = sub(ans, mult(fact[n - z], res[z]));
    }
    cout << ans << '\n';
    return 0;
}