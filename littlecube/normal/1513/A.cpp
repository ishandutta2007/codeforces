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

int t, n, k;
signed main()
{
    fast;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        deque<int> dq;
        for (int i = 1; i <= n; i++)
            dq.push_back(i);
        if (k > (n - 1) / 2)
            cout << -1 << '\n';
        else
        {
            for (int i = 1; i <= k; i++)
            {
                cout << dq.front() << " " << dq.back() << " ";
                dq.pop_front();
                dq.pop_back();
            }
            for(int i : dq)
                cout << i << " ";
            cout << '\n';
        }
    }
}