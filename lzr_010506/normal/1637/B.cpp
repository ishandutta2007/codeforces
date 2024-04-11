#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define ll long long
using namespace std;
const int N = 110;
int dp[N][N], mex[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n);
        rep(i, 1, n) cin >> a[i];
        rep(i, 1, n) 
        {
            set<int> s;
            rep(j, i, n)
            {
                s.insert(a[j]);
                mex[i][j] = 0;
                while(s.find(mex[i][j]) != s.end()) mex[i][j]++;
            }
        }
        ll ans = 0;
        rep(len, 1, n)
        {
        	rep(i, 1, n - len + 1)
        	{
                int j = i + len - 1;
                dp[i][j] = mex[i][j] + 1;
                rep(k, i, j - 1) dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                ans += dp[i][j];
            }
        }
        cout << ans << "\n";
    }
}