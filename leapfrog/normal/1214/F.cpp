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
const int N=600005;int m,n,ot[N];
struct bit
{
	int n;ll T[N];inline void init(int x) {n=x;}
	inline void add(int x,ll w) {for(;x<=n;x+=x&(-x)) T[x]+=w;}
	inline ll qry(int x) {ll r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
	inline ll qry(int l,int r) {return qry(r)-qry(l-1);}
}A,B;vector<int>va[N],vb[N];
struct ${int id;ll vl;char operator<($ b) const {return vl^b.vl?vl<b.vl:id<b.id;}}a[N],b[N];
int main()
{
	read(m,n);for(int i=1;i<=n;i++) read(a[i].vl),a[i].id=i,a[i].vl+=m;
	for(int i=1;i<=n;i++) read(b[i].vl),b[i].id=i;
	sort(a+1,a+n+1),sort(b+1,b+n+1),A.init(n),B.init(n*3);
	for(int i=n+1;i<=n*3;i++) a[i].vl=2e9+5,b[i]=($){b[i-n].id,b[i-n].vl+m};
	for(int i=1;i<=n;i++) if(a[i].vl>=b[i].vl)
	{
		int wh=upper_bound(b+1,b+n*3+1,a[i])-b;
		va[wh-i].push_back(i);
	}
	for(int i=1;i<=n*3;i++) if(a[i].vl>=b[i].vl)
	{
		int wh=lower_bound(a,a+n+2,b[i])-a-1;
		vb[i-wh].push_back(i);
	}
	for(int i=1;i<=n;i++) A.add(i,a[i].vl>=b[i].vl?a[i].vl:-a[i].vl);
	for(int i=1;i<=n*3;i++) B.add(i,a[i].vl>=b[i].vl?b[i].vl:-b[i].vl);
	ll rs=A.qry(1,n)-B.qry(1,n);int wh=0;
	for(int x=1;x<=n+n;x++)
	{
		for(auto i:va[x]) A.add(i,-2*a[i].vl);
		for(auto i:vb[x]) B.add(i,-2*b[i].vl);
		ll nw=A.qry(1,n)-B.qry(x+1,x+n);if(rs>nw) rs=nw,wh=x;
	}
	printf("%lld\n",rs);
	for(int i=1;i<=n;i++) ot[a[i].id]=b[i+wh].id;
	for(int i=1;i<=n;i++) printf("%d%c",ot[i],i==n?'\n':' ');
	return 0;
}