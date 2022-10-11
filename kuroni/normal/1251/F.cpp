#include <bits/stdc++.h>
#define fi first
#define se second
#define __lg(x) (x == 0 ? -1 : __lg(x))
using namespace std;
 
const int K = 6, MX = 3E5 + 5;
const long long MOD = 998244353, G = 3, LG = 24, ML = 19;
 
int n, k, u, q, x = 0, y = 0, red[K], cnt[MX];
long long iv, rt[LG + 1];
vector<pair<int, int>> ve;
 
long long pw(long long u, int p) {
    long long ret = 1;
    for (int i = __lg(p); i >= 0; i--) {
        (ret *= ret) %= MOD;
        if (p >> i & 1) {
            (ret *= u) %= MOD;
        }
    }
    return ret;
}
 
int reverse_bit(int u, int lg) {
    int ans = 0;
    for (int i = 0; i < lg; i++) {
        (ans <<= 1) ^= (u >> i & 1);
    }
    return ans;
}
 
struct polynomial {
    vector<long long> f;
 
    polynomial(int _sz = 0) {
        f = vector<long long>(_sz, 0);
    }
 
    polynomial ntt(bool inv = false) {
        if (inv) {
            reverse(f.begin() + 1, f.end());
        }
        int mx = 1 << ML;
        polynomial ans(mx);
        for (int i = 0; i < f.size(); i++) {
            ans.f[reverse_bit(i, ML)] = f[i];
        }
        for (int len = 1; len < mx; len += len) {
            long long r = rt[__lg(len) + 1];
            for (int i = 0; i < mx; i += 2 * len) {
                long long w = 1;
                for (int j = 0; j < len; j++) {
                    long long u = ans.f[i + j], v = ans.f[i + j + len];
                    ans.f[i + j] = (u + v * w) % MOD;
                    ans.f[i + j + len] = (u - v * w) % MOD;
                    (w *= r) %= MOD;
                }
            }
        }
        if (inv) {
            reverse(f.begin() + 1, f.end());
            for (long long &v : ans.f) {
                (v *= iv) %= MOD;
            }
        }
        return ans;
    }
 
    polynomial operator*(const polynomial &oth) const {
        polynomial ans(1 << ML);
        for (int i = 0; i < 1 << ML; i++) {
            ans.f[i] = f[i] * oth.f[i] % MOD;
        }
        return ans;
    }
} a(2), b(2), id(1), pol[K];
 
polynomial operator^(const polynomial &a, int p) {
    polynomial ans = id;
    for (int i = __lg(p); i >= 0; i--) {
        ans = ans * ans;
        if (p >> i & 1) {
            ans = ans * a;
        }
    }
    return ans;
}
 
void init() {
    rt[LG - 1] = pw(G, (MOD - 1) / (1LL << (LG - 1)));
    for (int i = LG - 2; i >= 0; i--) {
        rt[i] = (rt[i + 1] * rt[i + 1]) % MOD;
    }
    a.f = {1, 2}; b.f = {1, 1}; id.f = {1};
    a = a.ntt(); b = b.ntt(); id = id.ntt();
    iv = pw(1 << ML, MOD - 2);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        ve.push_back({u, 0});
    }
    for (int i = 1; i <= k; i++) {
        cin >> red[i];
        ve.push_back({red[i], -i});
    }
    sort(ve.begin(), ve.end());
    for (pair<int, int> &v : ve) {
        if (v.se < 0) {
            pol[-v.se] = ((a ^ x) * (b ^ (2 * y))).ntt(true);
        } else {
            if (cnt[v.fi] == 0) {
                x++;
            } else if (cnt[v.fi] == 1) {
                x--; y++;
            }
            cnt[v.fi]++;
        }
    }
    cin >> q;
    while (q--) {
        cin >> u; u /= 2;
        long long ret = 0;
        for (int i = 1; i <= k; i++) {
            int ch = u - red[i] - 1;
            if (ch >= 0 && ch < pol[i].f.size()) {
                (ret += pol[i].f[ch]) %= MOD;
            }
        }
        cout << (ret + MOD) % MOD << '\n';
    }
}