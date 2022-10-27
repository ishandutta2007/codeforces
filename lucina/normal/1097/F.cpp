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


#include<bits/stdc++.h>
using namespace std;
const int S = 7010;
const int N = 100010;
bitset<S> dp[N];
bitset<S> q[S];
bitset<S> pre[S];
int mu[S];
vector <int> factor[S];

void precalc() {
    mu[1] = 1;

    for (int i = 1 ; i <= 7000 ; ++ i) {
        pre[i].set(i, true);
        factor[i].push_back(i);
        for (int j = i + i ; j <= 7000 ; j += i) {
            mu[j] -= mu[i];
            pre[j].set(i, true);
            factor[j].push_back(i);
        }
    }

    for (int i = 1 ; i < S ; ++ i)
        (mu[i] += 2) &= 1;

     for (int i = 1 ; i <= 7000 ; ++ i) {
        for (int j : factor[i]) {
            if (mu[i / j]) q[j].set(i, true);
        }
     }

}

int main () {
    cin.tie(0)->sync_with_stdio(false);
    precalc();

    int n, nq;
    cin >> n >> nq;
    while (nq --) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, v;
            cin >> x >> v;
            dp[x] = pre[v];
        } else if (type == 2) {
            int x, y, z;
            cin >> x >> y >> z;
            dp[x] = dp[y] ^ dp[z];
        } else if (type == 3) {
            int x, y, z;
            cin >> x >> y >> z;
            dp[x] = dp[y] & dp[z];
        } else if (type == 4) {
            int x, v;
            cin >> x >> v;
            cout << (dp[x] & q[v]).count() % 2;
        } else assert(false);
    }
    cout << '\n';

}