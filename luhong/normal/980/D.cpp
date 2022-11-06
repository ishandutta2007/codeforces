#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[5010],cnt[5010],b[5010],tot=0,ans[5010];
int used[10100],prime[10100],TOT=0;
void ins(int x){if(++cnt[a[x]]==1)tot++;}
void init()
{
	for(int i=2;i<=10000;i++)
	{
		if(!used[i])prime[++TOT]=i;
		for(int j=1;i*prime[j]<=10000&&j<=TOT;j++)
		{
			used[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
bool check(int x)
{
	for(int i=2;i*i<=x;i++)if(x%i==0)return false;
	return true;
}
int main()
{
	int n;scanf("%d",&n);init();bool flag=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0){flag=1;continue;}
		int ok;
		if(a[i]<0)ok=-1;else ok=1;
		int x=a[i]*ok;a[i]=1;
		for(int j=1;j<=TOT;j++)
		{
			if(check(x)){a[i]*=x;break;}
			int tot=0;
			while(x%prime[j]==0)
			{
				tot++;x/=prime[j];
			}
			if(tot%2)a[i]*=prime[j];
		}
		b[i]=a[i]*ok;a[i]*=ok;
	}
	sort(b+1,b+n+1);int N=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+N+1,a[i])-b;
	int o;if(flag)o=lower_bound(b+1,b+N+1,0)-b;
	for(int l=1;l<=n;l++)
	for(int r=l;r<=n;r++)
	{
		if(l==r)memset(cnt,0,sizeof(cnt)),tot=0;
		ins(r);
		if(flag==1)
		{
			if(r-l+1==cnt[o])ans[1]++;
			else 
			{
				if(cnt[o])ans[tot-1]++;
				else ans[tot]++;
			}
		}
		else ans[tot]++;
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);return 0;
}
// 
//a=pi^kiki=ki%2a