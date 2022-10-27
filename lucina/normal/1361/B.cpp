#include<bits/stdc++.h>
using namespace std;
int const nax = 1e6 + 5;
long long const lim = 1e6 + 39;
const int mod = 1e9 + 7;

void plusle (int &a, int b) {
    if (( a += b) >= mod ) a -= mod ;
}
void minun (int &a, int b) {
    if ((a -= b) < 0) a += mod ;
}
int add (int a, int b) {
    return (( a += b ) >= mod ) ? a - mod  : a;
}
int sub (int a, int b) {
    return (( a -= b) < 0) ? a + mod : a;
}
int mul (int a, int b) {
    return 1LL * a * b % mod;
}
int power (int a, int b) {
    int res = 1;
    for (; b > 0 ; b >>= 1 , a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res ;
}

int n, p;
int t[nax];
int k[nax];

void solve () {
    scanf("%d %d", &n, &p);

    int f = 0;


    vector <int> v;

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", k + i);
        t[k[i]] ++ ;
        v.push_back(k[i]);
    }

    if (p == 1) {
        printf("%d\n", n % 2);
        for (int i = 1 ; i <= n ; ++ i)
            t[k[i]] = 0;
        return ;
    }

    int ans = 0;
    v.push_back(0);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    reverse(v.begin(), v.end());

    bool has = false;
    long long keep = 0;

    for (int i = 0 ; i < (int)v.size() ; ++ i) {
      ///  printf("I hate this problem %lld %d %d\n", keep, i, v[i]);
        int x = t[v[i]];
        int pow_dif = (i == 0) ? 0 : v[i - 1] - v[i];
                    
        if (keep != 0) {

            for (int j = 0 ; j < pow_dif ; ++ j) {
                if (keep * p <= lim) {
                    keep *= p;
                } else {
                    keep %= mod;
                    int tmp_keep = keep;
                    tmp_keep = mul(tmp_keep, power(p, pow_dif - j));
                    int res = ((((long long)tmp_keep - lim ) % mod) + mod) % mod;
                    ans = add(ans, mul(power(p, v[i]), res));
                    keep = lim;
                    break;
                }
            }
        }

        if (has) {
            if (keep <= x) {
                x -= keep;
                keep = 0;
                has = false;
            } else {
                keep -= x;
                x = 0;
            }
        }

        if (x) {
            if (x % 2) {
                keep ++;
                has = true;
            }
        }
    }

    keep %= mod;
    ans = add(ans, keep);

    printf("%d\n", (ans + mod) % mod);

    for (int i = 0 ; i < (int)v.size() ; ++ i)
        t[v[i]] = 0;

}

int main () {

    int T;

    for (scanf("%d", &T) ; T -- ; ) {
        solve() ;
    }
}
/*
    Good Luck
        -Lucina
*/