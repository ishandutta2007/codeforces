#include<bits/stdc++.h>
using namespace std;
int test,n,R,cnt,pa[222222],l[222222],r[222222],p[222222],cur,ff[222222];
char c;
bool f[222222],con[222222];
pair<int,int> a[222222];
long long dp[222222];
double pp[222222],ans[222222];
void dfs(int i)
{
	if (!l[i])
	{
		dp[i]=1;
		return;
	}
	dfs(l[i]);dfs(r[i]);
	if (con[i])
	{
		if (dp[l[i]]<dp[r[i]])
		{
			dp[i]=dp[l[i]];
			pp[l[i]]=1.00;pp[r[i]]=0.00;
		}
		else
		{
			dp[i]=dp[r[i]];
			pp[l[i]]=0.00;pp[r[i]]=1.00;
		}
	}
	else
	{
		dp[i]=dp[l[i]]+dp[r[i]];
		pp[l[i]]=(double)dp[i]/(double)dp[l[i]];
		pp[r[i]]=(double)dp[i]/(double)dp[r[i]];
	}
}
void dft(int i,double cur)
{
	if (!l[i])
	{
		ans[i]=cur;
		return;
	}
	dft(l[i],cur*pp[l[i]]);
	dft(r[i],cur*pp[r[i]]);
}
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&R);
		cur=0;cnt=0;
		while(c=getchar())
		{
			if (c==' ') continue;
			if (c=='S') 
			{
				f[cnt]=1;
				ff[cnt]=cur;
			}
			else if (c=='P')
			{
				f[cnt]=0;
				ff[cnt]=cur;
			}
			else if (c=='*')
			{
				++cnt;p[cnt]=cur;
			}
			else if (c=='(') cur++;
			else if (c==')') cur--;
			else break;
		}
		for (int i=1;i<cnt*2;i++) pa[i]=i;
		for (int i=1;i<cnt*2;i++) l[i]=r[i]=0;
		for (int i=1;i<cnt;i++) a[i]=make_pair(ff[i],i);
		sort(a+1,a+cnt);
		for (int i=cnt-1;i>=1;i--)
		{
			int rx=root(a[i].second),ry=root(a[i].second+1);
			++cnt;
			pa[rx]=pa[ry]=cnt;
			con[cnt]=f[a[i].second];l[cnt]=rx;r[cnt]=ry;
		}
		dfs(cnt);
		dft(cnt,(double)R);
		printf("REVOLTING ");
		for (int i=1;i<=(cnt+1)/2;i++) printf("%lld ",(long long)(ans[i]+0.5));
		printf("\n");
	}
	return 0;
}