#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

ll F(ll n)
{
    if (n % 2 == 0) return n / 2;
    ll cur = 3;
    while (cur * cur <= n && n % cur) cur++;
    if (cur * cur <= n) return 1 + F(n - cur);
    else return 1;
}

int main()
{
    cin >> n;
    cout << F(n) << endl;
    return 0;
}