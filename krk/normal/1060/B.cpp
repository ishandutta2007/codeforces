#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll res;

int Sum(ll x)
{
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    cin >> n;
    if (n < 9) { cout << n << endl; return 0; }
    ll me = 9;
    while (me <= n) me = 10ll * me + 9ll;
    me /= 10ll;
    cout << Sum(me) + Sum(n - me) << endl;
    return 0;
}