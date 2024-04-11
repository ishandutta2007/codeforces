#include <bits/stdc++.h>
#define ll long long 
using namespace std;
template <typename T> inline void chmin(T &x,const T &b) {x=min(x,b);}
const int inf=1039714778;
const ll llinf=1LL*inf*inf;
ll dp[2][10005];
int n,k;
int a[10005],b[10005];

int main()
{
	// freopen("input.txt","r",stdin);
	cin>>n>>k;
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<n;i++) scanf("%d",b+i);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;i++)
	{
		auto cur=dp[i&1],nxt=dp[(i&1)^1];
		memset(nxt,0x3f,sizeof(dp[0]));
		for(int j=0;j<=i;j++)
		{
			chmin(nxt[j+1],cur[j]+a[n-1-i]);
			chmin(nxt[j],cur[j]+b[n-1-i]+(ll)j*k);
		}
	}
	ll res=llinf;
	for(int i=0;i<=n;i++) chmin(res,dp[n&1][i]);
	cout<<res<<endl;
	return 0;
}