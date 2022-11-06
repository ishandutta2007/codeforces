#include<bits/stdc++.h>
using namespace std;
#define re register
#define ui unsigned int
#define ull unsigned long long
int a[1000100][8],cnt[1000100],p[200100],pr[1001000],pt[1010],ma[1000100],tot,n1,n2,dis[310][10100];
const int C=10,L=10;
unordered_map<long long,int>mb;
int abss(re int a)
{
	return a>0?a:-a;
}
void dfs(re int t,re int v,re int x,re long long fc,re int l1,re int l2)
{
	if(x>1e6||t>L)return;
	if(!ma[x])ma[x]=++n1;
	if(!mb[fc])mb[fc]=++n2;
	if(dis[ma[x]][mb[fc]]<=v)return;
	dis[ma[x]][mb[fc]]=v;
	for(re int i=0;i<=l1&&x<=1e6;i++)
	{
		for(re int j=0;j<=l2;j++)
		if(v+abss(i-j)<=C){
			dfs(t+1,v+abss(i-j),x,fc*(j+1),i,j);
		}x*=p[t+1];
	}
}
int main()
{
	re int ncn=1,xx,yy;
	pr[1]=1;
	for(re int i=2;i<=1e6;i++)
	{
		if(!cnt[i]){cnt[i]=1;a[i][0]=1;p[++tot]=i;}
		for(re int j=1;j<=tot&&i*p[j]<=1e6;j++)
		{
			memcpy(a[i*p[j]],a[i],sizeof(a[i]));
			cnt[i*p[j]]=cnt[i];
			if(!(i%p[j])){a[i*p[j]][cnt[i*p[j]]-1]++;break;}
			a[i*p[j]][cnt[i*p[j]]++]=1;
		}
		sort(a[i],a[i]+cnt[i]);
		reverse(a[i],a[i]+cnt[i]);
		re int num=1;
		for(re int ii=0;ii<cnt[i];ii++)
			for(re int jj=1;jj<=a[i][ii];jj++)num*=p[ii+1];
		pr[i]=num;
	}
	memset(dis,63,sizeof(dis));
	dfs(0,0,1,1,20,20);
	re int t;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d%d",&xx,&yy);
		xx=ma[pr[xx]];yy=ma[pr[yy]];
		re int ans=100;
		for(re int i=1;i<=n2;i++)if(dis[xx][i]+dis[yy][i]<ans)ans=dis[xx][i]+dis[yy][i];
		printf("%d\n",ans);
	}
}