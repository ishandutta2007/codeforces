#pragma GCC optimize("Ofast")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define LIM 10000000
#define RG register
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
#define set(a,v) memset(a,v,sizeof(a))
char buf[LIM],*P1,*P2;
int n,m,blk,cntB,lim=5e5,a[N],fa[N],rt[N],vl[N],cnt[N];struct Query {int op,l,r,x,ans;}q[N];
int min(RG int x,RG int y) {return x<y?x:y;}
int max(RG int x,RG int y) {return x>y?x:y;}
int rd()
{
	int res=0;bool fl=0;char c=0;while(!isdigit(c)) fl|=c=='-',c=gc();
	while(isdigit(c)) res=(res<<1)+(res<<3)+(c&15),c=gc();return fl?-res:res;
}
int findRt(RG int x) {return fa[x]==x?x:fa[x]=findRt(fa[x]);}
void merge(RG int x,RG int y)
{
	if(x>lim || y>lim || !rt[x]) return;
	if(rt[y]) fa[rt[x]]=rt[y];else rt[y]=rt[x],vl[rt[y]]=y;cnt[y]+=cnt[x];rt[x]=cnt[x]=0;
}
int build(RG int l,RG int r)
{
	int mx=0;
	for(RG int i=l;i<=r;++i) {mx=max(mx,a[i]);++cnt[a[i]];if(!rt[a[i]]) rt[a[i]]=i,vl[i]=a[i];fa[i]=rt[a[i]];}
	return mx;
}
int main()
{
	n=rd();m=rd();blk=sqrt(n);cntB=n/blk;if(n%blk) ++cntB;for(RG int i=1;i<=n;++i) a[i]=rd();
	for(RG int i=1;i<=m;++i) q[i].op=rd(),q[i].l=rd(),q[i].r=rd(),q[i].x=rd();
	for(RG int i=1,L,R,d,mx;i<=cntB;++i)
	{
		L=(i-1)*blk+1;R=min(i*blk,n);d=0;set(rt,0);set(cnt,0);mx=build(L,R);
		for(RG int j=1;j<=m;++j) if(q[j].l<=R && q[j].r>=L)
		{
			if(q[j].l<=L && q[j].r>=R)
			{
				if(q[j].op==1)
				{
					if(mx<=q[j].x<<1) {for(RG int k=q[j].x+1;k<=mx;++k) merge(k-d,k-q[j].x-d);mx=min(mx,q[j].x);}
					else {for(RG int k=1;k<=q[j].x;++k) merge(k-d,k+q[j].x-d);d-=q[j].x;mx-=q[j].x;}
				}else if(q[j].x-d<=lim) q[j].ans+=cnt[q[j].x-d];
			}
			else
			{
				for(RG int k=L;k<=R;++k) a[k]=vl[findRt(k)]+d;
				if(q[j].op==1)
				{
					for(RG int k=L;k<=R;++k) rt[a[k]-d]=cnt[a[k]-d]=0;d=0;
					for(RG int k=max(q[j].l,L);k<=min(q[j].r,R);++k) if(a[k]>q[j].x) a[k]-=q[j].x;mx=build(L,R);
				}else for(RG int k=max(q[j].l,L);k<=min(q[j].r,R);++k) if(a[k]==q[j].x) ++q[j].ans;
			}
		}
	}for(RG int i=1;i<=m;++i) if(q[i].op==2) printf("%d\n",q[i].ans);return 0;
}