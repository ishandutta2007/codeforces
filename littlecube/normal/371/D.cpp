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

ll n, m, cap[200005], cur[200005], dsu[200005], rk[200005], val[200005];

int find(int k)
{
    return dsu[k] == k ? k : dsu[k] = find(dsu[k]);
}

void merge(int x, int y)
{
    if (rk[x] <= rk[y])
    {
        dsu[x] = y;
        val[y] = max(val[x], val[y]);
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
        cin >> cap[i];
    cap[n + 1] = 1e17;
    for (int i = 1; i <= n + 1; i++)
        dsu[i] = val[i] = i, rk[i] = 1;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        ll t, p, x, k;
        cin >> t;
        if (t == 1)
        {
            cin >> p >> x;
            while (x > 0)
            {
                p = val[find(p)];
                
                if (cur[p] + x >= cap[p])
                {
                    x -= cap[p] - cur[p];
                    cur[p] = cap[p];
                    merge(find(p), find(p + 1));
                }
                else
                {
                    cur[p] += x;
                    x = 0;
                }
            }
        }
        else
        {
            cin >> k;
            cout << cur[k] << '\n';
        }
    }
}