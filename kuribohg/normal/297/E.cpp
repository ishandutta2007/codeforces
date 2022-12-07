#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=200010;
int n,a[MAXN],b[MAXN],d[MAXN],l[MAXN],r[MAXN],c[MAXN];
LL ans,e;
int pre[MAXN],next[MAXN];
int BIT[MAXN];
void Change(int x,int tar)
{
	for(int i=x;i<=n+n;i+=(i&(-i)))
		BIT[i]+=tar;
}
int Query(int x)
{
	int con=0;
	for(int i=x;i>0;i^=(i&(-i)))
		con+=BIT[i];
	return con;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),d[a[i]]=i,d[b[i]]=i;
	for(int i=1;i<=n+n;i++)
		if(!pre[d[i]]) pre[d[i]]=i;
		else next[pre[d[i]]]=i;
	for(int i=1;i<=n+n;i++)
		if(next[i]) Change(i,1);
		else Change(i,-1);
	for(int i=1;i<=n+n;i++)
		if(next[i])
		{
			c[d[i]]=Query(next[i]-1)-Query(i);
			Change(next[i],2);
		}
	for(int i=1;i<=n;i++) l[i]=max(a[i],b[i])-min(a[i],b[i])-1,r[i]=n+n-2-l[i];
	ans=(LL)n*(LL)(n-1)*(LL)(n-2)/6LL;
	for(int i=1;i<=n;i++) ans-=(LL)(l[i]-c[i])*(LL)(r[i]-c[i])/4LL;
	for(int i=1;i<=n;i++) e+=(LL)c[i]*(LL)(n-c[i]-1);
	printf("%I64d\n",ans-e/2);
	return 0;
}