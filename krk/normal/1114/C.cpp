#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 9000000000000000000ll;

ll n, b;

ll Get(ll n, ll x)
{
    ll res = 0;
    while (n >= x) {
        res += n / x;
        n /= x;
    }
    return res;
}

int main()
{
    ll mn = Inf;
    scanf("%I64d %I64d", &n, &b);
    for (ll i = 2; i * i <= b; i++)
        if (b % i == 0) {
            int cnt = 0;
            while (b % i == 0) { b /= i; cnt++; }
            mn = min(mn, Get(n, i) / cnt);
        }
    if (b > 1)
        mn = min(mn, Get(n, b));
    cout << mn << endl;
    return 0;
}