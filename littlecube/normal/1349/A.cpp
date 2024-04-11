/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC comment(linker,"/stack:200000000")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
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
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq[100000];

int n, b[200005], id[200005] = {0, 0, 0}, res = 1;
vector<int> p = {2};

signed main()
{
    fast;
    for (int i = 2; i <= 200000; i += 2)
        b[i] = 2;
    for (int i = 3; i <= 200000; i += 2)
    {
        if (!b[i])
        {
            id[i] = p.size();
            p.pb(i);
            for (int j = i; j <= 200000; j += i)
                b[j] = i;
        }
    }

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        while (a > 1)
        {
            int k = b[a], _p = 0;
            while (a % k == 0)
                a /= k, _p++;
            pq[id[k]].push(_p);
        }
    }
    for (int i = 0; i < p.size(); i++)
    {
        int _p = 0;
        if (pq[i].size() == n - 1)
            _p = pq[i].top();
        if (pq[i].size() == n)
        {
            _p = pq[i].top();
            pq[i].pop();
            _p = pq[i].top();
        }
        for (int j = 1; j <= _p; j++)
            res *= p[i];
    }
    cout << res << '\n';
}