#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
int const nax = 100;
int max_bit (ll x) {
    int res = 0;
    for (; x > 0 ; x >>= 1) res ++;
    return res;
}
ll u, v;

int p[nax];


int main () {

    scanf("%lld %lld", &u, &v);

    if (max_bit(u) > max_bit(v)) return !printf("-1");

    if (u % 2 != v % 2) return !printf("-1");
    if (u == v && v == 0) return !printf("0");
    if (u == v) return !printf("1\n%lld\n", u);

    ///safe case
    int ret = max(max_bit(u), max_bit(v));

    /// u is xor
    /// v is sum

    bool force_carry = false;
    for (int i = 0 ; i <= 62 ; ++ i) {
        int x = (u & (1LL << i)) ? 1 : 0;
        int sum = (v & (1LL << i)) ? 1 : 0;
        if (x == 0 && sum == 0) {
            if (force_carry)  {
                p[i - 1] += 2;
            }
        }
        else if (x == 1 && sum == 1) {
            if (!force_carry) p[i] ++ ;
            else {
                p[i] ++;
                p[i - 1] += 2;
            }
        }
        else if (x == 1 && sum == 0) {
            if (force_carry) {
                p[i] ++ ;
                force_carry = true;
            }
            else {
                p[i - 1] += 2;
                p[i] ++ ;
                force_carry = true;
            }
        }
        else if (x == 0 && sum == 1) {
            if (force_carry) {
                force_carry = false;
            }
            else p[i - 1] += 2;
        }
        else throw;
    }
    int ma = 0;
    for (int i = 0 ; i <= 62 ; ++ i) {
        ma = max(ma, p[i]);
    }
    vector<ll> ans(ma, 0LL);
    for (int i = 0 ; i <= 62 ; ++ i) {
        if (p[i] > 0) {
            for (int j = 0 ;j < p[i] ; ++ j)
            ans[j] ^= (1LL << i);
        }
    }
    ll x = 0, sum = 0;


    for (ll & j : ans) {
        x ^= j;
        sum += j;
    }
    if (x != u && sum != v) return !printf("-1");
    printf("%d\n", ma);

    for (ll &j :ans)
        printf("%lld ", j);
}
/*
    Good Luck
        -Lucina
*/