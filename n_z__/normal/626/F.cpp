#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1e9+7;
long long a[201],n,k;
namespace subtask1{
	array<int,201>b,c;
	int dfs(int now,int g,int ns)
	{
		/*cout<<now+1<<','<<g<<','<<ns<<','<<a[now+1]<<endl;
		for(int x=1;x<=g;x++)
		cout<<b[x]<<' ';cout<<endl;
		for(int x=1;x<=g;x++)
		cout<<c[x]<<' ';cout<<endl;*/
		if(now==n)return 1;
		int ret=0;
		for(int x=1;x<=g;x++)
		if(ns+c[x]-a[now+1]<=k){int d=c[x]-a[now+1];c[x]=a[now+1],(ret+=dfs(now+1,g,ns+d))%=p;c[x]+=d;}
		b[g+1]=a[now+1];
		c[g+1]=a[now+1];
		(ret+=dfs(now+1,g+1,ns))%=p;
		b[g+1]=0;
		c[g+1]=0;
		return ret;
	}
	void solve()
	{
		cout<<dfs(0,0,0)<<endl;
	}
}
namespace subtask3{
	int dp[2][201][1001];
	void solve()
	{
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;
		for(int x=0;x<n;x++)
		{
    		for(int y=0;y<=n;y++)
    		for(int z=y*(a[x+1]-a[x]);z<=k;z++)
    		{
    			int s=y*(a[x+1]-a[x]),r=dp[x&1][y][z-s]; 
    			(dp[!(x&1)][y][z]+=r*(y+1)%p)%=p;
    			if(y!=n)(dp[!(x&1)][y+1][z]+=r)%=p;
    			if(y!=0)(dp[!(x&1)][y-1][z]+=r*y%p)%=p;
    		}
		    memset(dp[x&1],0,sizeof(dp[x&1]));
		}
    	int ans=0;
		for(int x=0;x<=k;x++)(ans+=dp[n&1][0][x])%=p;
		cout<<ans<<endl;
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
main()
{
	cin>>n>>k;
	for(int x=1;x<=n;x++)
	cin>>a[x];
	sort(a+1,a+1+n/*,cmp*/); 
	//if(n<=10)subtask1::solve();
	/*else */subtask3::solve();
}