/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma loop_opt(on)
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
//using namespace __gnu_pbds;

ll n, d, arr[100005];
ll ans;



signed main()
{
    fast;
    cin >> n >> d;
    
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
   
    for (int i = 1, ldx = 1; i <= n; i++)
    {
        while(arr[i] - arr[ldx] > d)
            ldx++;
        ll cnt = max(1, i - ldx);
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << '\n';
}