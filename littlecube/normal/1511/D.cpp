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

int n, k;
int pre = 0;
string s;
signed main()
{
    fast;
    cin >> n >> k;
    for (int i = 0; i < k;i++)
    {
        s += (char)('a' + i);
        for (int j = i + 1; j < k;j++)
        {
            s += (char)('a' + i);
            s += (char)('a' + j);
        }
    }
        for (int i = 0; i < n; i++)
        {
            cout << s[i % s.length()];
        }
}