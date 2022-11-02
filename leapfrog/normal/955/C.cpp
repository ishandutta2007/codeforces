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
typedef long double LL;
inline char chk(ll x) {ll y=sqrt(x);return y*y==x;}
inline LL ksm(LL x,int q) {LL r=1;for(;q;q>>=1,x*=x) if(q&1) r*=x;return r;}
ll tn[5000005];int ut,Q,n;
inline void init()
{
	for(int i=3;i<=59;i++) for(int j=1;j<=1000000;j++)
	{
		LL vl=ksm(j,i);if(vl>1000000000000000000) break;
		ll v=(ll)vl;if(v>1&&!chk(v)) tn[++ut]=v;
	}
	sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1;
}
inline ll solve(ll vl) {return upper_bound(tn+1,tn+ut+1,vl)-tn+(int)sqrt(vl);}
int main() {for(read(Q),init();Q--;) {ll l,r;read(l),read(r),printf("%lld\n",solve(r)-solve(l-1));}}