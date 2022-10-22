#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int mod = 1000000007;
 
int inv2 = (mod + 1) / 2;
int T;
ll m;
 
int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d", &m);
        int res = 1;
        if (m >= 2) {
            res++;
            ll got = (m - 2) / 2;
            ll hm = got / 2;
            if (hm > 0) {
                ll fir = 2, lst = (fir + hm - 1);
                int add = ll(fir + lst) % mod * (hm % mod) % mod;
                res = (res + add) % mod;
            }
            if (got % 2) res = (ll(res) + 2ll + hm) % mod;
        }
        printf("%d\n", res);
    }
    return 0;
}