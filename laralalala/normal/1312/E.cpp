#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 505

ll dp[MAXN][MAXN],a[MAXN];
ll res[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    for(int i=0;i<n;i++)
        dp[i][i]=a[i];
    for(int i=1;i<n;i++)
        for(int j=0;j+i<n;j++)
        {
            for(int u=j;u<j+i;u++)
            {
                if(dp[j][u]==dp[u+1][j+i] && dp[j][u]!=-1)
                {
                    dp[j][j+i]=dp[j][u]+1;
                    res[j][j+i]=i;
                }
                res[j][j+i]=max(res[j][j+i],res[j][u]+res[u+1][j+i]);
            }
        }

    db(n-res[0][n-1])
    return 0;
}