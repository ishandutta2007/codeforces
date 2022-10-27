#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 100;

signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector <int> pr(N, -1);
    for(int i = 2; i < N; i++)
    {
        if(pr[i] == -1)
        {
            int j = i;
            while(j < N)
            {
                pr[j] = i;
                j += i;
            }
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector <int> a(n + 1);
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            int f = a[i];
            int res = 1;
            while(pr[f] != -1)
            {
                int c = pr[f];
                if(f % (c * c) == 0)
                {
                    res *= c * c;
                    f /= (c * c);
                }
                else
                {
                    f /= c;
                }
            }
            a[i] /= res;
        }
        vector <vector <int> > dp(n + 1, vector <int> (k + 1, 1e9));
        dp[0][0] = 0;
        set <int> st;
        st.insert(0);
        map <int, int> mp;
        for(int i = 1; i <= n; i++)
        {
            if(mp.count(a[i]))
            {
                st.insert(-mp[a[i]]);
            }
            mp[a[i]] = i;
            set <int> :: iterator it;
            it = st.begin();
            int k1 = 0;
            while(k1 <= k)
            {
                if(it == st.end())
                {
                    break;
                }
                for(int j = 0; j + k1 <= k; j++)
                {
                    dp[i][j + k1] = min(dp[i][j + k1], dp[-*it][j] + 1);
                }
                it++;
                k1++;
            }
        }
        int res = 1e9;
        for(int j = 0; j <= k; j++)
        {
            res = min(res, dp[n][j]);
     //       cout << dp[n][j] << " ";
        }
   //     cout << "\n";
        cout << res << "\n";
    }
    return 0;
}