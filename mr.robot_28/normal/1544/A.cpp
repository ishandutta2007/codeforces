#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 2e6;

signed main()
{
//  ios_base::sync_with_stdio(0);
//  cin.tie(0);
//  cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        while(n > 0)
        {
            ans = max(ans,n % 10);
            n /= 10;
        }
        cout << ans << "\n";
    }
    return 0;
}