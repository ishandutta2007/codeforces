//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,a[1000005],b[1000005],tn[2000005],ut,fa[2000005],mx[2000005][2],cn[2000005],cc[2000005];
inline void lsh(int &x) {x=lower_bound(tn+1,tn+ut+1,x)-tn;}
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void ins(int *a,int w) {if(w>*a) a[1]=*a,*a=w;else if(w!=*a&&w>=a[1]) a[1]=w;}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y;}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),read(b[i]),tn[++ut]=a[i],tn[++ut]=b[i];
	sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1;for(int i=1;i<=ut;i++) fa[i]=i;
	int res=0;for(int i=1;i<=n;i++) lsh(a[i]),lsh(b[i]),mrg(a[i],b[i]);
	for(int i=1;i<=ut;i++) cc[getf(i)]++;
	for(int i=1;i<=n;i++) cn[getf(a[i])]++,ins(mx[getf(a[i])],a[i]),ins(mx[getf(a[i])],b[i]);
	for(int i=1;i<=ut;i++) if(getf(i)==i)
	{
		if(cn[i]>cc[i]) return puts("-1"),0;
		if(cn[i]==cc[i]) res=max(res,*mx[i]);else res=max(res,mx[i][1]);
	}
	return printf("%d\n",tn[res]),0;
}