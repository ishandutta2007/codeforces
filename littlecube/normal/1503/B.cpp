/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t, n, a = 1, b = 2;
signed main()
{
    fast;
    cin >> n;
    vector<pii> A, B;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ((i + j) % 2)
                A.pb((pii{i, j}));
            else
                B.pb((pii{i, j}));
    for (int i = 1; i <= n * n; i++)
    {
        cin >> t;
        if (t == a)
        {
            if (!B.empty())
            {
                cout << b << " " << B.back().F << " " << B.back().S << endl;
                B.pop_back();
            }
            else
            {
                cout << 3 << " " << A.back().F << " " << A.back().S << endl;
                A.pop_back();
            }
        }
        else if (t == b)
        {
            if (!A.empty())
            {
                cout << a << " " << A.back().F << " " << A.back().S << endl;
                A.pop_back();
            }
            else
            {
                cout << 3 << " " << B.back().F << " " << B.back().S << endl;
                B.pop_back();
            }
        }
        else
        {
            if (!A.empty())
            {
                cout << a << " " << A.back().F << " " << A.back().S << endl;
                A.pop_back();
            }
            else
            {
                cout << b << " " << B.back().F << " " << B.back().S << endl;
                B.pop_back();
            }
        }
    }
}