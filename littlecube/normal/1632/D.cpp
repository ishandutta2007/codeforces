/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/extc++.h>
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

int N, gcdtable[25][200005];

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> gcdtable[0][i];
    for (int p = 1; p <= 20; p++)
        for (int i = 1; i <= N; i++)
            gcdtable[p][i] = __gcd(gcdtable[p - 1][i], gcdtable[p - 1][min(N, i + (1 << (p - 1)))]);
    auto gcd = [&](int L, int R)
    {
        int p = __lg(R - L + 1);
        return __gcd(gcdtable[p][L], gcdtable[p][R - (1 << p) + 1]);
    };
    int pre = 1, ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int L = pre, R = i;
        while(L < R)
        {
            int mid = (L + R + 1) / 2;
            if(gcd(mid, i) > i - mid + 1)
                R = mid - 1;
            else
                L = mid;
        }
        if(gcd(L, i) == i - L + 1)
            pre = i + 1, ans++;
        cout << ans << " \n"[i == N];
    }
}