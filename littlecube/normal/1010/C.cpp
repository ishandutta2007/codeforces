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

int n, k, vis[100005], d = 1e9;
vector<int> a;

signed main()
{
    fast;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        a[i] %= k;

    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();

    d = k;
    for (int i = 1; i < n; i++)
        d = min(d, __gcd(a[i] - a[i - 1], k));

    queue<int> q;
    vis[0] = 1;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i : a)
            if (!vis[(u + i) % d])
            {
                vis[(u + i) % d] = 1;
                q.push((u + i) % d);
            }
    }
    for (int i = d; i < k; i++)
        vis[i] = vis[i - d];

    int cnt = 0;
    for (int i = 0; i < k; i++)
        cnt += vis[i];
    cout << cnt << '\n';
    for (int i = 0; i < k; i++)
        if (vis[i])
            cout << i << ' ';
}