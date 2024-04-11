/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
//#include <bits/extc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(_x) emplace_back(_x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, k, arr[300005], val[1000005], ans;
signed main()
{
    fast;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++)
        val[arr[i]]++;
    for (int i = 1; i <= 1000000; i++)
        val[i] += val[i - 1];
    ans = min(k + 1, arr[1]);
    for (int i = k + 1; i <= arr[1]; i++)
    {
        int res = 0;
        for (int j = i; j <= 1000000;j += i)
            res += (val[min(1000000, j + k)] - val[j - 1]);
        if(res == n)
            ans = i;
    }
    cout << ans << '\n';
}