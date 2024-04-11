/**Nephren is the best girl**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int MOD = 1e9+7;
const int chtholly = 0;
int T;

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
    {
        int n,k,z,i,j,maxi = -1;
        cin>>n>>k>>z;
        int val[n];
        int dp[n][6];
        int quick[n];
        for(i=0;i<n;i++)
            cin>>val[i];
        int cur = 0;
        for(i=0;i<n;i++)
        {
            cur += val[i];
            quick[i] = cur;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<z+1;j++)
            {
                if(2*j+i <= k )
                {
                    dp[i][j] = quick[k-2*j]+j*(val[i]+val[i+1]);
                    maxi = max(maxi,dp[i][j]);
                }
            }
        }
        cout<<maxi<<"\n";
    }
    return chtholly;
}

/**
    I lied. Ithea is better than Nephren.
    JK
**/