#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c[710],f[710];

inline ll C(int x, int y)
{
    long double ret = 1;
    for(int i = 1; i <= x - y; i ++)
    	ret = ret * (i + y) / i;
    return (ll)ret;
}

int main()
{
    ll k;
    cin >> k;
    for(int i = 1; i <= 700; i ++)
    	f[i] = C(i + 6, 7);
    for(int i = 700; i; i --)
        c[i] = k / f[i], k %= f[i];
    int t = 700;
    while(!c[t]) t --;
    for(int i = t; i; i --)
        cout << string(c[i],'a') << "bcdefgh";
    cout << endl << "abcdefgh" << endl;
    return 0;
}