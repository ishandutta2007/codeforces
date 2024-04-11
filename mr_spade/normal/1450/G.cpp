#include<cstdio>
#include<algorithm>
using std::min;
using std::max;
const int N=5005,M=20;
int n,a,b;
char s[N];
int id[M<<1],idx;
int l[M],r[M],cnt[M];
int pre[N],suc[N];
bool bk[1<<M],dp[1<<M];
inline bool check(int l,int r,int cnt)
{
	return a*(r-l+1)<=cnt*b;
}
void dfs(int x,int s,int cl,int cr,int cc)
{
	if(x==idx)
	{
		bk[s]=check(cl,cr,cc);
		return;
	}
	dfs(x+1,s,cl,cr,cc);
	dfs(x+1,s|1<<x,min(cl,l[x]),max(cr,r[x]),cc+cnt[x]);
	return;
}
signed main()
{
	register int i,j;
	scanf("%d%d%d",&n,&a,&b);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
		if(!id[s[i]-'a'])
			id[s[i]-'a']=++idx;
	for(i=0;i<26;i++)
		id[i]--;
	for(i=0;i<idx;i++)
		l[i]=n+1;
	for(i=1;i<=n;i++)
		l[id[s[i]-'a']]=min(l[id[s[i]-'a']],i),r[id[s[i]-'a']]=max(r[id[s[i]-'a']],i),cnt[id[s[i]-'a']]++;
	for(i=0;i<idx;i++)
	{
		for(j=r[i];j<=n;j++)
			pre[j]|=1<<i;
		for(j=1;j<=l[i];j++)
			suc[j]|=1<<i;
	}
	dfs(0,0,n+1,0,0);
	dp[0]=1;
	for(int s=1;s<1<<idx;s++)
	{
		if(bk[s])
			for(i=0;i<idx;i++)
				if(s>>i&1)
					dp[s]|=dp[s^(1<<i)];
		for(i=0;i<idx;i++)
			if(((s&pre[r[i]])|(s&suc[r[i]+1]))==s)
				dp[s]|=(dp[s&pre[r[i]]]&&dp[s&suc[r[i]+1]]);
	}
	int u=(1<<idx)-1,ans=0;
	for(i=0;i<26;i++)
		if(id[i]>=0&&dp[u^(1<<id[i])])
			ans++;
	printf("%d ",ans);
	for(i=0;i<26;i++)
		if(id[i]>=0&&dp[u^(1<<id[i])])
			printf("%c ",'a'+i);
	putchar('\n');
	return 0;
}