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

int N, Z[100005], pos, p[100005];
string s;
vector<pii> v;

signed main()
{
    fast;
    cin >> s;
    N = s.size();
    for (int i = 1; i < N; i++)
    {
        if (i <= pos + Z[pos] - 1)
        {
            Z[i] = min(Z[i - pos], pos + Z[pos] - i);
            if (i + Z[i] - 1 == pos + Z[pos] - 1)
                while (i + Z[i] < N && s[Z[i]] == s[i + Z[i]])
                    Z[i]++;
        }
        else
            while (i + Z[i] < N && s[Z[i]] == s[i + Z[i]])
                Z[i]++;
        if(i + Z[i] > pos + Z[pos])
            pos = i;
    }
    Z[0] = N;
    for (int i = 0; i < N; i++)
        p[Z[i]]++;
    for (int i = N; i >= 0; i--)
        p[i] += p[i + 1];
    for (int i = N - 1; i >= 0; i--)
        if(i + Z[i] == N)
            v.emplace_back(pii{Z[i], p[Z[i]]});
    cout << v.size() << '\n';
    for(auto [l, c] : v)
        cout << l << " " << c << '\n';
}