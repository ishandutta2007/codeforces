#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
const int mod = 998244353;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        if(n < 61 && (1LL << (n - 1)) < k)
        {
            cout << -1 << "\n";
            continue;
        }
        int j = 0;
        vector <int> ans;
        vector <ll> dp(n + 1, 1);
        vector <bool> fl(n + 1, 0);
        for(int i = 1; i <= n; i++)
        {
            dp[i] = (1LL << (i - 1));
            if(fl[i - 1] || dp[i] > 1e18)
            {
                fl[i] = 1;
            }
        }
        int len = n;
        int maxval = 0;
        while(len > 0)
        {
            int maxt = 0;
            for(int j = 1; j <= len; j++)
            {
                if(fl[len - j])
                {
                    maxt = j;
                    break;
                }
                if(dp[len - j] < k)
                {
                    k -= dp[len - j];
                }
                else
                {
                    maxt = j;
                    break;
                }
            }
         //   cout << maxt << " ";
            for(int j = maxt; j >= 1; j--)
            {
                ans.push_back(j + maxval);
            }
            maxval += maxt;
            len -= maxt;
        }
        for(auto p : ans)
        {
            cout << p << " ";
        }
        cout << "\n";
    }
    return 0;
}