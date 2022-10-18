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

int N, cnt;
ll ans, l[100005], r[100005];
string s;

signed main()
{
    fast;
    cin >> s;
    N = s.size();
    for (int i = 0; i < N; i++)
        if (s[i] == '?')
            cin >> l[i] >> r[i];
    priority_queue<pii, vector<pii>, greater<>> pq;
    for (int i = 0; i < N; i++)
    {
        cnt += (s[i] == '(' ? 1 : -1);
        if (s[i] == '?')
        {
            ans += r[i];
            pq.push(pii{l[i] - r[i], i});
            s[i] = ')';
        }
        if (cnt < 0)
        {
            if (pq.empty())
            {
                cout << -1 << '\n';
                return 0;
            }
            cnt += 2;
            s[pq.top().S] = '(';
            ans += pq.top().F;
            pq.pop();
        }
    }
    if (cnt == 0)
    {
        cout << ans << '\n';
        cout << s << '\n';  
    }
    else
        cout << -1 << '\n';
}