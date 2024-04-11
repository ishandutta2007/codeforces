/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma loop_opt(on)
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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
//using namespace __gnu_pbds;

ll n, arr[305], tag[305], dsu[305], rk[305];
bool adj[305][305];
vector<int> v[305];

int find(int k)
{
    return dsu[k] == k ? k : dsu[k] = find(dsu[k]);
}

void merge(int x, int y)
{
    if (x == y)
        return;
    if (rk[x] <= rk[y])
    {
        dsu[x] = y;
        rk[y] += rk[x];
    }
    else
        merge(y, x);
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n + 1; i++)
        dsu[i] = i, rk[i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            if (c == '1')
                merge(find(i), find(j));
        }
    for (int i = 1; i <= n; i++)
    {
        tag[i] = find(i);
        v[tag[i]].emplace_back(arr[i]);
    }
    for (int i = 1; i <= n; i++)
        sort(v[i].begin(), v[i].end(), greater<int>());
    for (int i = 1; i <= n; i++)
    {
        arr[i] = v[tag[i]].back();
        v[tag[i]].pop_back();
    }
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " \n"[i == n];
}