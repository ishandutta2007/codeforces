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

int N, Q, ans[26][1505];
char s[1505];

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> s[i];
    for (int i = 1; i <= N; i++)
    {
        int cnt[26] = {};
        for (int j = i; j <= N; j++)
        {
            cnt[s[j] - 'a']++;
            for (int k = 0; k < 26; k++)
                ans[k][j - i + 1 - cnt[k]] = max(ans[k][j - i + 1 - cnt[k]], j - i + 1);
        }
    }
    for (int i = 1; i <= N; i++)
        for (int k = 0; k < 26; k++)
            ans[k][i] = max(ans[k][i], ans[k][i - 1]);
    cin >> Q;
    while(Q--)
    {
        char c;
        int i;
        cin >> i >> c;
        cout << ans[c - 'a'][i] << '\n';
    }
}