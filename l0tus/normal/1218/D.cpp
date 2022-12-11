#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
int n, m;
vector<pii> edge[100001];
vector<vector<int>> cycle;

int dep[100001];
int par[100001];
int val[100001];
void dfs(int x, int p) {
    dep[x] = dep[p] + 1;
    par[x] = p;
    for (pii i : edge[x]) {
        if (i.fs == p) continue;
        if (dep[i.fs]) {
            if (dep[i.fs] < dep[x]) {
                cycle.emplace_back(1, i.se);
                for (int j = x; j != i.fs; j = par[j]) {
                    cycle.back().push_back(val[j]);
                }
            }
            continue;
        }
        val[i.fs] = i.se;
        dfs(i.fs, x);
    }
}

const int sz = 17;
int bit_rev(int x) {
    int r = 0;
    for (int i = 0; i < sz; ++i) {
        r <<= 1;
        r |= x & 1;
        x >>= 1;
    }
    return r;
}

int pw(int x, int p, int mod) {
    int r = 1;
    while (p) {
        if (p & 1) r = (llong)r * x % mod;
        x = (llong)x * x % mod;
        p >>= 1;
    }
    return r;
}

void FFT(vector<int> &A, int mod, bool rev) {
    for (int i = 0; i < (1 << sz); ++i) {
        int j = bit_rev(i);
        if (i < j) swap(A[i], A[j]);
    }
    for (int i = 1; i < (1 << sz); i <<= 1) {
        for (int j = 0; j < (1 << sz); j += i + i) {
            for (int k = 0; k < i; ++k) {
                int t = A[i + j + k];
                A[i + j + k] = (A[j + k] + mod - t) % mod;
                A[j + k] = (A[j + k] + t) % mod;
            }
        }
    }
    if (rev) {
        int R = pw(1 << sz, mod - 2, mod);
        for (int i = 0; i < (1 << sz); ++i) {
            A[i] = (llong)A[i] * R % mod;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        sum ^= w;
        edge[u].emplace_back(v, w);
        edge[v].emplace_back(u, w);
    }
    dfs(1, 0);
    vector<int> A1(1 << sz, 0);
    A1[0] = 1;
    vector<int> A2 = A1;
    FFT(A1, mod1, 0);
    FFT(A2, mod2, 0);
    for (const vector<int> &V : cycle) {
        vector<int> M1(1 << sz, 0);
        for (int i : V) ++M1[i];
        vector<int> M2 = M1;
        FFT(M1, mod1, 0);
        FFT(M2, mod2, 0);
        for (int i = 0; i < (1 << sz); ++i) {
            A1[i] = (llong)A1[i] * M1[i] % mod1;
            A2[i] = (llong)A2[i] * M2[i] % mod2;
        }
    }
    FFT(A1, mod1, 1);
    FFT(A2, mod2, 1);
    pii ans = pii(1 << sz, 0);
    for (int i = 0; i < (1 << sz); ++i) {
        if (A1[i] == 0 && A2[i] == 0) continue;
        ans = min(ans, pii(i ^ sum, A1[i]));
    }
    printf("%d %d\n", ans.fs, ans.se);
    return 0;
}