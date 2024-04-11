/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

int t, m, cnt, used[105];
pii mem[105];

void defragment()
{
    stable_sort(mem + 1, mem + 1 + m, [](pii p1, pii p2)
         {if((p1.F != 0) == (p2.F != 0))return p1.S < p2.S;  return p1.F > p2.F; });
    for (int i = 1; i <= m; i++)
        mem[i].S = i;
}

void alloc(int n)
{
    ++cnt;
    for (int i = 1; i <= m - n + 1; i++)
    {
        bool valid = true;
        for (int j = i; j <= i + n - 1; j++)
            if (mem[j].F != 0)
                valid = false;
        if (valid)
        {
            used[cnt] = 1;
            for (int j = i; j <= i + n - 1; j++)
                mem[j].F = cnt;
            cout << cnt << '\n';
            return;
        }
    }
    --cnt;
    cout << "NULL\n";
}

void erase(int x)
{
    if (x > t || x < 0 || !used[x])
        cout << "ILLEGAL_ERASE_ARGUMENT\n";
    else
    {
        used[x] = 0;
        for (int i = 1; i <= m; i++)
            if (mem[i].F == x)
                mem[i].F = 0;
    }
}

signed main()
{
    cin >> t >> m;
    string s;
    ll n;
    for (int i = 1; i <= t; i++)
    {
        cin >> s;
        if (s == "alloc")
            cin >> n, alloc(n);
        if (s == "erase")
            cin >> n, erase(n);
        if (s == "defragment")
            defragment();
        //for (int i = 1; i <= m; i++)
        //    cout << mem[i].F << " \n"[i == m];
    }
}