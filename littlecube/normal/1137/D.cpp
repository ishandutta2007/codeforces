/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
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

#define LOCAL

signed main()
{
    int k;
    string s;
    while (1)
    {

        cout << "next 0" << endl;
        cin >> k;
        for (int i = 1; i <= k; i++)
            cin >> s;

        cout << "next 0 1" << endl;
        cin >> k;
        for (int i = 1; i <= k; i++)
            cin >> s;

        if (k == 2)
            break;
    }
    while (1)
    {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        cin >> k;
        for (int i = 1; i <= k; i++)
            cin >> s;
        if (k == 1)
            break;
    }
    cout << "done" << endl;
}