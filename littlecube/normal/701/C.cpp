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

int N, cnt[256], res, ans = 1e9;
char c[100005];

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> c[i];
    for (int i = 1; i <= N; i++)
        if (cnt[c[i]] == 0)
            cnt[c[i]] = -1, res--;
    int rdx = 1;
    for (int i = 1; i <= N; i++)
    {
        while (rdx <= N && res < 0)
        {
            cnt[c[rdx]]++;
            if(cnt[c[rdx]] == 0)
                res++;
            rdx++;
        }
        if(res == 0)
            ans = min(ans, rdx - i);
        cnt[c[i]]--;
        if(cnt[c[i]] == -1)
            res--;
    }
    cout << ans << '\n';
}