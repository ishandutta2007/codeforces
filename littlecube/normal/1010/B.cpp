/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int m, n;
bool lie[32];

signed main()
{
    fast;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int ver = 0;
        cout << m << endl;
        cin >> ver;
        if(ver == 0)
            return 0;
        if(ver == -1)
            lie[i] = 1;
    }
    int L = 1, R = m;
    for (int i = n; i < 60; i++)
    {
        int ver = 0, mid = (L + R) / 2;
        cout << mid << endl;
        cin >> ver;
        if(ver == 0)
            return 0;
        if(lie[i % n])
            ver = -ver;
        if(ver == 1)
            R = mid - 1;
        else
            L = mid + 1;
    }
}