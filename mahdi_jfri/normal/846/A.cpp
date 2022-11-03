#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair <ll , ll>

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair

#define X first
#define Y second

#define LB(x) (x & -(x))
#define BIT(a,b) ((ll)((a)&(1<<(b)))==0 ? false : true)

const ll MAXN=1e2+10;

ll a[MAXN];
ll dp[MAXN];
ll dp2[MAXN];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin>>n;

	for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    if (a[0])
    {
        dp[0]=0;
        dp2[0]=1;
    }
    else
    {
        dp[0]=0;
        dp2[0]=0;
    }

    for(ll j=1;j<n;j++)
    {
        if (a[j])
        {
            dp[j]=dp[j-1];
            dp2[j]=dp2[j-1]+1;
        }
        else
        {
            dp[j]=min(dp[j-1]+1 , dp2[j-1]);
            dp2[j]=dp2[j-1];
        }
    }

    cout<<n-dp[n-1];
}