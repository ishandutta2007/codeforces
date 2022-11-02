//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct node{int wh,le,ri,r,q;}t[100005];int n,T[300005],tn[300005],ut,K;ll res=0;
inline char cmp1(node a,node b) {return a.r>b.r;}
inline char cmp2(node a,node b) {return a.q<b.q;}
inline int lsh(int x) {return lower_bound(tn+1,tn+ut+1,x)-tn;}
inline void add(int x,int w) {for(;x<=ut;x+=x&(-x)) T[x]+=w;}
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
inline void cdq(int l,int r)
{
	int md=(l+r)>>1;if(l==r) return;else cdq(l,md),cdq(md+1,r);
	sort(t+l,t+md+1,cmp2),sort(t+md+1,t+r+1,cmp2);int le=l,ri=l-1;
//	puts("---------------------");
//	for(int i=l;i<=r;i++) printf("%d %d %d %d %d\n",t[i].wh,t[i].le,t[i].ri,t[i].r,t[i].q);
	for(int i=md+1;i<=r;i++)
	{
		while(le<=md&&t[i].q-t[le].q>K) add(t[le++].wh,-1);
		while(ri<md&&t[ri+1].q-t[i].q<=K) add(t[++ri].wh,1);
		res+=qry(t[i].ri)-qry(t[i].le-1);
	}
	for(int i=le;i<=ri;i++) add(t[i].wh,-1);
}
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(t[i].wh),read(t[i].r),read(t[i].q);
	for(int i=1;i<=n;i++) tn[++ut]=t[i].wh,tn[++ut]=t[i].le=t[i].wh-t[i].r,tn[++ut]=t[i].ri=t[i].wh+t[i].r;
	sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1,sort(t+1,t+n+1,cmp1);
	for(int i=1;i<=n;i++) t[i].le=lsh(t[i].le),t[i].ri=lsh(t[i].ri),t[i].wh=lsh(t[i].wh);
	return cdq(1,n),printf("%lld\n",res),0;
}