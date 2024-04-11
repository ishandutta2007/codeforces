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

int N, T;
signed main()
{
    fast;
    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<int> v;
        for (int i = 1; i <= N; i++)
        {
            int val;
            cin >> val;
            for (bool b = 0; b == 0;)
            {
                if (val == 1)
                {
                    v.pb(1);
                    b = 1;
                }
                else if (val == v.back() + 1)
                {
                    v.back()++;
                    b = 1;
                }
                if (!b)
                    v.pop_back();
            }
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << ".\n"[i == v.size() - 1];
        }
    }
}