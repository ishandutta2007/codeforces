#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int t,n,f,x,cur,ddp[2222][22],dp[2222][22],y;
int fuck[2222][22],fucked[2222][22],ans[22],res,anp[22];
vector<int> a,b;
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);a.clear();b.clear();
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			f=1;cur=0;
			while(x)
			{
				cur+=(x%10)*f;
				x/=10;f=-f;
			}
			cur=(cur%11+11)%11;
			if (f>0) b.push_back(cur);
			else a.push_back(cur);   
		}
		memset(ddp,0,sizeof(ddp));
		ddp[0][0]=1;
		for (int i=0;i<a.size();i++)
		{
			for (int j=0;j<=a.size();j++)
			{
				for (int k=0;k<11;k++)
				dp[j][k]=0;
			}
			for (int j=0;j<=i;j++)
			{
				for (int k=0;k<11;k++)
				{
					add(dp[j+1][(k+a[i])%11],ddp[j][k]);
					add(dp[j][(k-a[i]+11)%11],ddp[j][k]);
				}
			}
			for (int j=0;j<=a.size();j++)
			{
				for (int k=0;k<11;k++)
				ddp[j][k]=dp[j][k];
			}
		}
		x=(a.size()+1)-(a.size()+1)/2;
		y=a.size()+1-x;
		for (int i=0;i<11;i++)
		{
			anp[i]=ddp[y][i];
			for (int j=1;j<x;j++) anp[i]=1ll*anp[i]*j%mod;
			for (int j=1;j<=y;j++) anp[i]=1ll*anp[i]*j%mod;
		}
		memset(fucked,0,sizeof(fucked));
		fucked[0][0]=1;
		for (int i=0;i<b.size();i++)
		{
			for (int j=0;j<=b.size();j++)
			{
				for (int k=0;k<11;k++)
				fuck[j][k]=0;
			}
			for (int j=0;j<=i;j++)
			{
				for (int k=0;k<11;k++)
				{
					add(fuck[j+1][(k+b[i])%11],1ll*fucked[j][k]*(x+j)%mod);
					add(fuck[j][(k-b[i]+11)%11],1ll*fucked[j][k]*(y+i-j)%mod);
				}
			}
			for (int j=0;j<=b.size();j++)
			{
				for (int k=0;k<11;k++)
				fucked[j][k]=fuck[j][k];
			}
		}
		memset(ans,0,sizeof(ans));
		for (int i=0;i<=b.size();i++)
		{
			for (int j=0;j<11;j++)
			{
				add(ans[j],fucked[i][j]);
			}
		}
		res=1ll*anp[0]*ans[0]%mod;
		for (int i=1;i<=10;i++)
		{
			add(res,1ll*anp[i]*ans[11-i]%mod);
		}
		printf("%d\n",res);
	}
	return 0;
}