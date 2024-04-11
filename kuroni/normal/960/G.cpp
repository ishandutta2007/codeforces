#include <bits/stdc++.h>
#define fi first
#define se second
#define lg(x) (x == 0 ? -1 : __lg(x))
using namespace std;

const long long MOD = 998244353, G = 3, LG = 24;

int n, a, b;
long long rt[LG + 1];

long long pw(long long u, int p) {
    long long ret = 1;
    for (int i = lg(p); i >= 0; i--) {
        (ret *= ret) %= MOD;
        if (p >> i & 1) {
            (ret *= u) %= MOD;
        }
    }
    return ret;
}

struct polynomial {
    vector<long long> f;

    polynomial(int _sz = 0) {
        f = vector<long long>(_sz, 0);
    }

    int reverse_bit(int u, int lg) {
        int ans = 0;
        for (int i = 0; i < lg; i++) {
            (ans <<= 1) ^= (u >> i & 1);
        }
        return ans;
    }

    polynomial ntt(int lg, bool inv = false) {
        if (inv) {
            reverse(f.begin() + 1, f.end());
        }
        int mx = (1 << lg);
        polynomial ans(mx);
        for (int i = 0; i < f.size(); i++) {
            ans.f[reverse_bit(i, lg)] = f[i];
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
            long long iv = pw(1LL * mx, MOD - 2);
            for (long long &v : ans.f) {
                (v *= iv) %= MOD;
            }
        }
        return ans;
    }

    polynomial operator*(polynomial oth) {
        int a = (int)f.size() - 1;
        int b = (int)oth.f.size() - 1;
        int lg = __lg(a + b) + 1;
        polynomial fa = ntt(lg), fb = oth.ntt(lg);
        polynomial ans(1 << lg);
        for (int i = 0; i < 1 << lg; i++) {
            ans.f[i] = fa.f[i] * fb.f[i] % MOD;
        }
        ans = ans.ntt(lg, true);
        ans.f.resize(a + b + 1);
        return ans;
    }

    bool operator>(const polynomial& oth) const {
        return f.size() > oth.f.size();
    }
};
priority_queue<polynomial, vector<polynomial>, greater<polynomial>> pq;

long long fct(int u) {
    long long ans = 1;
    for (int i = 1; i <= u; i++) {
        (ans *= i) %= MOD;
    }
    return ans;
}

void init() {
    rt[LG - 1] = pw(G, (MOD - 1) / (1LL << (LG - 1)));
    for (int i = LG - 2; i >= 0; i--) {
        rt[i] = (rt[i + 1] * rt[i + 1]) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n >> a >> b;
    if (a + b - 1 > n || a == 0 || b == 0) {
        return cout << 0, 0;
    }
    if (n == 1) {
        return cout << 1, 0;
    }
    for (int i = 0; i <= n - 2; i++) {
        polynomial cur(2);
        cur.f[0] = 1; cur.f[1] = i;
        pq.push(cur);
    }
    while (pq.size() > 1) {
        polynomial u = pq.top(); pq.pop();
        polynomial v = pq.top(); pq.pop();
        pq.push(u * v);
    }
    long long ans = (pq.top().f[n - a - b + 1] + MOD) % MOD;
    a--; b--;
    (ans *= fct(a + b) * pw(fct(a), MOD - 2) % MOD * pw(fct(b), MOD - 2) % MOD) %= MOD;
    cout << ans;
}