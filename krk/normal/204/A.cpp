#include <iostream>
using namespace std;

typedef long long ll;

ll l, r;

int Digits(ll x)
{
    int res = 0;
    do {
        res++;
        x /= 10LL;
    } while (x);
    return res;
}

ll Get(ll x)
{
    int dig = Digits(x);
    ll pw = 1LL;
    for (int i = 0; i < dig - 1; i++) pw *= 10LL;
    ll res = 0;
    ll mid = 1LL;
    for (int i = 1; i < dig; i++) {
        res += 9LL * mid;
        if (i >= 2) mid *= 10LL;
    }
    ll msd = x / pw, lsd = x % 10LL;
    res += (msd - 1LL) * mid;
    x %= pw;
    x /= 10LL;
    if (msd > lsd) res += x;
    else res += x + 1LL;
    return res;
}

int main()
{
    cin >> l >> r;
    cout << Get(r) - Get(l - 1LL) << endl;
    return 0;
}