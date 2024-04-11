#include <bits/stdc++.h>
using namespace std;

const int N = 200005, M = 35, H = 17, MOD = 998244353, INV = 998236737;

int n, m, cur = 1, inv = 1;
long long u, f[1 << H], g[1 << H], h[1 << H], ans[M + 1];
vector<long long> bas, le, ri, val[M - H + 1];

bool eliminate(long long u) {
    for (long long &v : bas) {
        u = min(u, u ^ v);
    }
    if (u == 0) {
        return false;
    }
    bas.push_back(u);
    for (int i = (int)bas.size() - 1; i > 0; i--) {
        if (bas[i] > bas[i - 1]) {
            swap(bas[i], bas[i - 1]);
        } else {
            break;
        }
    }
    return true;
}

void fwht(long long f[1 << H], bool inv = false) {
    for (int len = 1; 2 * len <= (1 << H); len <<= 1) {
        for (int i = 0; i < (1 << H); i += 2 * len) {
            for (int j = 0; j < len; j++) {
                long long u = f[i + j], v = f[i + len + j];
                f[i + j] = (u + v) % MOD;
                f[i + len + j] = (u - v) % MOD;
            }
        }
    }
    
    if (inv) {
        for (int i = 0; i < (1 << H); i++) {
            (f[i] *= INV) %= MOD;
        }
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> u;
        if (!eliminate(u)) {
            (cur *= 2) %= MOD;
        }
    }
    for (long long &v : bas) {
        (__lg(v) < H ? le : ri).push_back(v);
    }
    for (int msk = 0; msk < (1 << le.size()); msk++) {
        long long cur = 0;
        for (int i = 0; i < (int)le.size(); i++) {
            if (msk >> i & 1) {
                cur ^= le[i];
            }
        }
        f[cur]++;
    }
    fwht(f);
    for (int msk = 0; msk < (1 << ri.size()); msk++) {
        long long cur = 0;
        for (int i = 0; i < (int)ri.size(); i++) {
            if (msk >> i & 1) {
                cur ^= ri[i];
            }
        }
        long long lst = (1 << H) - 1;
        val[__builtin_popcountll(cur & (~lst))].push_back(cur & lst);
    }
    for (int i = 0; i <= M - H; i++) {
        fill(g, g + (1 << H), 0);
        for (long long &v : val[i]) {
            g[v]++;
        }
        fwht(g);
        for (int j = 0; j < (1 << H); j++) {
            h[j] = f[j] * g[j] % MOD;
        }
        fwht(h, true);
        for (int j = 0; j < (1 << H); j++) {
            (ans[i + __builtin_popcount(j)] += h[j]) %= MOD;
        }
    }
    for (int i = 0; i <= m; i++) {
        cout << ((ans[i] + MOD) * cur) % MOD << " ";
    }
}