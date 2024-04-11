/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <bits/extc++.h>
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

int n, q, color[60];
signed main()
{
    fast;
    cin >> n >> q;
    vector<pii> v;
    for (int i = 1; i <= n;i++)
    {
        int x;
        cin >> x;
        if(color[x] == 0)
            color[x] = i;
    }
    for (int i = 1; i <= q;i++)
    {
        int x;
        cin >> x;
        for (int i = 1; i <= 50; i++)
            if(color[i] != 0 && color[i] < color[x])
                color[i]++;
        cout << color[x] << " ";
        color[x] = 1;
    }
}