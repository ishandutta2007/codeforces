#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int a[100001],b[100001],dp[100001];
inline int qp(int A,int P=mod-2,int MOD=mod)
{
    register int Return=1;
    while(P)
    {
        if(P&1)
        {
            Return*=A;
            Return%=MOD;
        }
        A*=A;
        A%=MOD;
        P>>=1;
    }
    return Return%MOD;
}
main()
{
	int n,m;
	cin>>n>>m;
	for(int x=1;x<=n;x++)cin>>a[x];
	for(int x=1;x<=n;x++)cin>>b[x];
	for(int x=n,y=qp(m);x>=1;dp[x]%=mod,x--)
	if(!a[x]&&!b[x])dp[x]=m*(m-1)/2%mod*y%mod*y%mod+dp[x+1]*y%mod;
	else if(!a[x])dp[x]=(m-b[x])*y%mod+dp[x+1]*y%mod;
	else if(!b[x])dp[x]=(a[x]-1)*y%mod+dp[x+1]*y%mod;
	else if(a[x]>b[x])dp[x]=1;
	else if(a[x]<b[x])dp[x]=0;
	else dp[x]=dp[x+1];
	cout<<dp[1];
}