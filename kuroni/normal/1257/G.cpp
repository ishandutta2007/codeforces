#include <bits/stdc++.h>
#define __lg(x) (x == 0 ? -1 : __lg(x))
using namespace std;

const int N = 200005, MOD = 998244353, LG = 23, G = 3;

int n, p, ret = N;
long long ans = 1, rt[LG];
map<int, int> ma;

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
    int ret = 0;
    for (int i = 0; i < lg; i++) {
        (ret <<= 1) ^= (u >> i & 1);
    }
    return ret;
}

struct polynomial {
    vector<long long> f;

    polynomial(int _sz = 0) {
        f = vector<long long>(_sz, 0);
    }

    polynomial ntt(int mx, bool inv = false) {
        polynomial ans(mx);
        int lg = __lg(mx);
        if (inv) {
            reverse(f.begin() + 1, f.end());
        }
        for (int i = 0; i < f.size(); i++) {
            ans.f[reverse_bit(i, lg)] = f[i];
        }
        for (int len = 1; len < mx; len += len) {
            for (int i = 0; i < mx; i += 2 * len) {
                long long r = rt[__lg(len) + 1];
                long long w = 1;
                for (int j = 0; j < len; j++) {
                    long long u = ans.f[i + j], v = ans.f[i + j + len];
                    ans.f[i + j] = (u + w * v) % MOD;
                    ans.f[i + j + len] = (u - w * v) % MOD;
                    (w *= r) %= MOD;
                }
            }
        }
        if (inv) {
            reverse(f.begin() + 1, f.end());
            long long iv = pw(mx, MOD - 2);
            for (long long &v : ans.f) {
                (v *= iv) %= MOD;
            }
        }
        return ans;
    }

    polynomial operator*(polynomial &oth) {
        int nd = f.size() + oth.f.size() - 1, mx = (1 << (__lg(nd) + 1));
        polynomial a = ntt(mx), b = oth.ntt(mx), ans(mx);
        for (int i = 0; i < mx; i++) {
            ans.f[i] = a.f[i] * b.f[i] % MOD;
        }
        ans = ans.ntt(mx, true);
        ans.f.resize(nd);
        return ans;
    }

    bool operator>(const polynomial &oth) const {
        return f.size() > oth.f.size();
    }
};
priority_queue<polynomial, vector<polynomial>, greater<polynomial>> pq;

void init() {
    long long cur = pw(G, (MOD - 1) / (1 << LG));
    for (int i = LG - 1; i >= 0; i--) {
        (cur *= cur) %= MOD;
        rt[i] = cur;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        ma[p]++;
    }
    for (auto &v : ma) {
        polynomial cur(v.second + 1);
        for (int i = 0; i <= v.second; i++) {
            cur.f[i] = 1;
        }
        pq.push(cur);
    }
    while (pq.size() >= 2) {
        polynomial u = pq.top(); pq.pop();
        polynomial v = pq.top(); pq.pop();
        pq.push(u * v);
    }
    polynomial u = pq.top();
    cout << (u.f[(u.f.size() - 1) / 2] + MOD) % MOD;
}