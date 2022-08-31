/*
    28.12.2018 19:15:46
*/

#include <bits/stdc++.h>

using namespace std;

long long mod = 998244353, g = 3, ginv = 332748118, inv2 = (mod + 1) / 2;

vector< long long > powg(1048576, -1), powginv(1048576, -1);

long long powMod(long long a, long long n, long long mod = mod) {
    long long ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

long long findG(long long mod = mod) {
    vector< long long > d;
    long long n = mod - 1;
    if (!(n & 1)) {
        d.push_back(2);
        while (!(n & 1)) {
            n >>= 1;
        }
    }
    long long p = 3;
    while (n > 1) {
        if (n % p == 0) {
            d.push_back(p);
            while (n % p == 0) {
                n /= p;
            }
        }
        p += 2;
    }
    n = mod - 1;
    for (auto& item : d) {
        item = n / item;
    }
    long long g = 2;
    while (true) {
        bool ok = true;
        for (auto k : d) {
            if (powMod(g, k, mod) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            break;
        }
        ++g;
    }
    return g;
}

long long getPowG(int n) {
    // if (powg[n] == -1) {
    //     powg[n] = powMod(g, (mod - 1) / (1048576ll) * n, mod);
    // }
    return powg[n];
}

long long getPowGinv(int n) {
    // if (powginv[n] == -1) {
    //     powginv[n] = powMod(ginv, (mod - 1) / (1048576ll) * n, mod);
    // }
    return powginv[n];
}

vector< long long > ntt(vector< long long >& v, bool inv = false) {
    if (v.size() == 1) {
        return v;
    }
    int n = 1;
    int p2 = 0;
    while (n < v.size()) {
        n <<= 1;
        ++p2;
    }
    long long k = (1 << (20 - p2));
    v.resize(n, 0);
    assert(mod % n == 1);
    vector< long long > v1(n / 2), v2(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        v1[i] = v[2 * i];
        v2[i] = v[2 * i + 1];
    }
    vector< long long > ntt1 = ntt(v1, inv), ntt2 = ntt(v2, inv);
    vector< long long > ans(n);
    if (inv) {
        for (int i = 0; i < n / 2; ++i) {
            ans[i] = (ntt1[i] + powginv[(i * k)] * ntt2[i]);
            ans[n / 2 + i] = (ntt1[i] + powginv[((i + n / 2) * k)] * ntt2[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (ans[i]) {
                ans[i] = ans[i] % mod * inv2 % mod;
            }
        }
    } else {
        for (int i = 0; i < n / 2; ++i) {
            ans[i] = (ntt1[i] + powg[(i * k)] * ntt2[i]);
            ans[n / 2 + i] = (ntt1[i] + powg[((i + n / 2) * k)] * ntt2[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (ans[i] >= mod) {
                ans[i] = ans[i] % mod;
            }
        }
    }
    return ans;
}

vector< long long > mul(vector< long long >& a, vector< long long >& b) {
    int n = 1;
    while (n < a.size() + b.size() - 1) {
        n <<= 1;
    }
    a.resize(n, 0);
    b.resize(n, 0);
    vector< long long > ntta = ntt(a), nttb = ntt(b);
    for (int i = 0; i < n; ++i) {
        ntta[i] = ntta[i] * nttb[i] % mod;
    }
    vector< long long > ans = ntt(ntta, true);
    while (ans.size() > 1 && ans.back() == 0) {
        ans.pop_back();
    }
    return ans;
}

vector< long long > sqr(vector< long long >& a) {
    int n = 1;
    while (n < a.size() * 2 - 1) {
        n <<= 1;
    }
    a.resize(n, 0);
    vector< long long > ntta = ntt(a);
    for (int i = 0; i < n; ++i) {
        ntta[i] = ntta[i] * ntta[i] % mod;
    }
    vector< long long > ans = ntt(ntta, true);
    while (ans.size() > 1 && ans.back() == 0) {
        ans.pop_back();
    }
    return ans;
}

// vector< long long > pow(vector< long long > v, int n) {
//     vector< long long > ans = {1};
//     while (n > 0) {
//         if (n & 1) {
//             ans = mul(ans, v);
//         }
//         v = sqr(v);
//         n >>= 1;
//     }
//     return ans;
// }

int main() {
    powg[0] = 1; powginv[0] = 1;
    powg[1] = powMod(g, (mod - 1) / 1048576, mod);
    powginv[1] = powMod(ginv, (mod - 1) / 1048576, mod);
    for (int i = 1; i < powg.size(); ++i) {
        powg[i] = powg[i - 1] * powg[1] % mod;
        powginv[i] = powginv[i - 1] * powginv[1] % mod;
    }
    int n, k;
    cin >> n >> k;
    n /= 2;
    vector< long long > v(1048576, 0);
    for (int i = 0; i < k; ++i) {
        int d;
        cin >> d;
        v[d] = 1;
    }
    vector< long long > v1 = ntt(v);
    for (int i = 0; i < v1.size(); ++i) {
        v1[i] = powMod(v1[i], n);
    }
    v = ntt(v1, true);
    long long ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i]) {
            ans = (ans + v[i] * v[i]) % mod;
        }
    }
    cout << ans << '\n';
    return 0;
}