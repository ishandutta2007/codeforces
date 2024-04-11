//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,m,K,p,a[100005],cnt[100005],h[100005];
inline char check(ll x)
{
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
	for(int i=1;i<=n;i++) if(x-h[i]<1ll*m*a[i]) q.push(make_pair(x/a[i],i)),cnt[i]=0;
	for(int z=1;z<=m&&!q.empty();z++) for(int j=1;j<=K&&!q.empty();j++)
	{
		int i=q.top().second;if(q.top().first<z) return 0;else q.pop(),cnt[i]++;
		if(x+1ll*cnt[i]*p<h[i]+1ll*m*a[i]) q.push(make_pair((x+1ll*cnt[i]*p)/a[i],i));
	}
	return q.empty();
}
int main()
{
	read(n),read(m),read(K),read(p);ll l=0,r=1e18,rs=r;
	for(int i=1;i<=n;i++) read(h[i]),read(a[i]),l=max(l,(ll)a[i]),r=max(r,1ll*n*h[i]+a[i]);
	while(l<=r) {ll md=(l+r)>>1;if(check(md)) r=md-1,rs=md;else l=md+1;}
	return printf("%lld\n",rs),0;
}