#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n,m,k,K,a[MAXN],c[MAXN*30];
LL res,ans[MAXN];
struct Query
{
	int l,r,id;
	friend bool operator<(const Query &p,const Query &q)
	{
		return p.l/K==q.l/K?p.r<q.r:p.l/K<q.l/K;
	}
}Q[MAXN];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	K=(int)sqrt(n)+1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].l--,Q[i].id=i;
	sort(Q+1,Q+m+1);
	for(int i=1;i<=n;i++) a[i]^=a[i-1];
	for(int i=Q[1].l;i<=Q[1].r;i++)
		res+=c[a[i]^k],c[a[i]]++;
	ans[Q[1].id]=res;
	for(int i=2;i<=m;i++)
	{
		if(Q[i].l<Q[i-1].l)
		{
			for(int j=Q[i-1].l-1;j>=Q[i].l;j--)
				res+=c[a[j]^k],c[a[j]]++;
		}
		if(Q[i].l>Q[i-1].l)
		{
			for(int j=Q[i-1].l;j<Q[i].l;j++)
				c[a[j]]--,res-=c[a[j]^k];
		}
		if(Q[i].r>Q[i-1].r)
		{
			for(int j=Q[i-1].r+1;j<=Q[i].r;j++)
				res+=c[a[j]^k],c[a[j]]++;
		}
		if(Q[i].r<Q[i-1].r)
		{
			for(int j=Q[i-1].r;j>Q[i].r;j--)
				c[a[j]]--,res-=c[a[j]^k];
		}
		ans[Q[i].id]=res;
	}
	for(int i=1;i<=m;i++) printf("%I64d\n",ans[i]);
	return 0;
}