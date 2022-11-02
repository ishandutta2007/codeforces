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
template<typename T,typename...L>inline void read(T &x,L&...ln) {read(x),read(ln...);}/*}}}*/
const int N=100005;
int n,m,q,b[N];ll nws=0;set<ll>st;
inline ll qry()
{
	auto ia=st.lower_bound(nws);ll rs=1e18;
	if(ia!=st.end()) rs=min(rs,*ia-nws);
	if(ia!=st.begin()) rs=min(rs,nws-*--ia);
	return rs;
}
inline void solve(int l,int r,int x) {if((r-l+1)&1) nws+=(l&1?x:-x);}
int main()
{
	read(n,m,q);for(int i=1,x;i<=n;i++) read(x),nws+=(i&1?x:-x);
	ll nw=0;for(int i=1;i<=m;i++) read(b[i]),b[i]=(i&1?b[i]:-b[i]);
	for(int i=1;i<n;i++) nw+=b[i];
	for(int i=n;i<=m;i++) nw+=b[i],st.insert((i-n)&1?-nw:nw),nw-=b[i-n+1];
	printf("%lld\n",qry());for(int l,r,x;q--;) read(l,r,x),solve(l,r,x),printf("%lld\n",qry());
	return 0;
}