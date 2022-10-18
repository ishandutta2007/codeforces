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

int N, M, T;
signed main()
{
    fast;
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> M;
        cout << 3 * N << '\n';
        for (int i = 1; i <= N; i += 2)
        {
            cout << "2 " << i << " " << i + 1 << '\n';
            cout << "1 " << i << " " << i + 1 << '\n';
            cout << "2 " << i << " " << i + 1 << '\n';
            cout << "2 " << i << " " << i + 1 << '\n';
            cout << "1 " << i << " " << i + 1 << '\n';
            cout << "2 " << i << " " << i + 1 << '\n';
        }
    }
}