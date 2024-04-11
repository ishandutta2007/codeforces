#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

#include <bits/stdc++.h>
using namespace std;
 
const int N = 2005, MOD = 1E9 + 7;
 
int n, m, r, x[N], y[N], b[N];
long long tot = 0, rem = 0, fct[N], ifc[N], inv[N];
bitset<N> bi[N];
 
void init() {
    inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }
    fct[0] = ifc[0] = 1;
    for (int i = 1; i < N; i++) {
        fct[i] = (fct[i - 1] * i) % MOD;
        ifc[i] = (ifc[i - 1] * inv[i]) % MOD;
    }
}
 
long long C(int n, int k) {
    if (k > n) {
        return 0;
    }
    return fct[n] * ifc[k] % MOD * ifc[n - k] % MOD;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n >> m >> r;
    long long tot = 0, rem = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (max(abs(x[i] - x[j]), abs(y[i] - y[j])) > r) {
                bi[i].set(j);
            }
            (tot += C(n, m) * b[i] % MOD * b[j]) %= MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            long long tot = C((bi[i] & bi[j]).count(), m);
            long long le = C(bi[i].count(), m);
            long long ri = C(bi[i].count(), m);
            (rem += (le + ri - tot) * b[i] % MOD * b[j]) %= MOD;
        }
    }
    cout << ((tot - rem) % MOD + MOD) % MOD;
}