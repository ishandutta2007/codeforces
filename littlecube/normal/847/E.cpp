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

int N;
vector<int> p, star;

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> c;
        if (c == 'P')
            p.emplace_back(i);
        else if (c == '*')
            star.emplace_back(i);
    }
    int L = 1, R = 2 * N;
    while (L < R)
    {
        int mid = (L + R) / 2, idx = 0;
        for (int i : p)
        {
            int l = 1e9;
            while (idx < star.size() && star[idx] < i)
                l = min(l, star[idx]), idx++;
            if(l <= N && (i - l) > mid)
            {
                idx = 0;
                break;
            }
            if (l > N)
                while (idx < star.size() && star[idx] <= i + mid)
                    idx++;
            else
                while (idx < star.size() && star[idx] <= i + max(mid - 2 * (i - l), (mid - (i - l)) / 2))
                    idx++;
        }
        if (idx == star.size())
            R = mid;
        else
            L = mid + 1;
    }
    cout << L << '\n';
}