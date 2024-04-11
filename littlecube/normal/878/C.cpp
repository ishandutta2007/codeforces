/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
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
// using namespace __gnu_pbds;

int N, k;

struct M
{
    int mx[11], mi[11];
} m[50004];


bool win(M m1, M m2) 
{
    bool win = 0;
    for (int i = 1; i <= 10; i++)
        win |= m1.mx[i] > m2.mi[i];
    return win;
}

struct cmp
{
    bool operator()(M m1, M m2) const
    {
        return (win(m1, m2) && !win(m2, m1));
    }
};


map<M, int, cmp> mp;

signed main()
{
    fast;
    cin >> N >> k;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cin >> m[i].mx[j];
            m[i].mi[j] = m[i].mx[j];
        }
        auto it = mp.lower_bound(m[i]);
        int acc = 1;
        while (it != mp.end() && win(m[i], it->F) && win(it->F, m[i]))
        {
            acc += it->S;
            for (int j = 1; j <= k; j++)
                m[i].mi[j] = min(m[i].mi[j], it->F.mi[j]), m[i].mx[j] = max(m[i].mx[j], it->F.mx[j]);
            it = mp.erase(it);
        }
        mp[m[i]] = acc;
        cout << mp.begin()->S << '\n';
    }
}