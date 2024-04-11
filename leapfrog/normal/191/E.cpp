//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=100005;int n,T[N];ll K,a[N],tn[N],ut;
inline void add(int x,int w) {for(;x;x-=x&(-x)) T[x]+=w;}//
inline int qry(int x) {int r=0;for(;x<=ut;x+=x&(-x)) r+=T[x];return r;}
inline char chk(ll vl)
{
	ll rs=0;for(int i=0;i<=n;i++) add(a[i],1);
	for(int i=0;i<=n;i++) add(a[i],-1),rs+=qry(lower_bound(tn+1,tn+ut+1,tn[a[i]]+vl)-tn);
	return rs>=K;
}
int main()
{
	read(n,K);for(int i=1;i<=n;i++) read(a[i]),a[i]+=a[i-1],tn[i]=a[i];
	sort(tn+1,tn+(ut=n)+1),ut=unique(tn+1,tn+ut+1)-tn-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(tn+1,tn+ut+1,a[i])-tn;
	ll l=-1e14,r=1e14,rs=1e14;// >=K 
	while(l<=r) {ll md=(l+r)>>1;if(chk(md)) rs=md,l=md+1;else r=md-1;}
	return printf("%lld\n",rs),0;
}