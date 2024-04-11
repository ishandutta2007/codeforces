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
const int N=200005;int n,K,a[N];
struct ${ll l,r;int cnt;inline char operator<($ b) const {return l<b.l;}};
inline char check(ll v)
{
	multiset<$>s;s.insert(($){1ll,1ll,1});ll cn=1,mx=1;
	for(int i=1;i<=n;i++)
	{
		if(s.empty()) return mx>=K;
		$ x=*s.begin();s.erase(s.begin());ll l=x.l,r=x.r;int c=x.cnt;
		l^r?s.insert(($){l+1,r,1}),0:0;if(c==2) s.insert(($){l,r,1});
		if(l+1==v) return mx>=K;
		ll r1=min(v,(a[i]-1)/2+l+1),r2=min(v,a[i]/2+l+1);cn+=r1-l+r2-l-3,mx=max(mx,cn);
		(r1^r2?s.insert(($){r2,r2,1}),0:0);if(r1>l+1) s.insert(($){l+2,r1,2});
	}return mx>=K;
}
int main()
{
	read(n,K);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1,greater<int>());ll rs=0;
	//return printf("%d\n",check(3)),0;
	for(ll L=0,R=400002,md=(L+R)>>1;L<=R;md=(L+R)>>1)
		if(check(md)) rs=md,R=md-1;else L=md+1;
	return printf("%lld\n",rs-1),0;
}