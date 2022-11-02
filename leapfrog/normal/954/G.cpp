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
int n,r;ll a[500005],K,c[500005],cf[500005];
inline char chk(ll vl)
{
	ll sm=0,w;for(int i=1;i<=n;i++) cf[i]=c[i];
	for(int i=1;i<=n&&sm<=K;i++) {cf[i]+=cf[i-1];if(cf[i]<vl) sm+=(w=vl-cf[i]),cf[i]+=w,cf[min(i+r*2,n)+1]-=w;}
	return sm<=K;
}
int main()
{
	read(n),read(r),read(K);ll le=0,ri=0,rs=0;
	for(int i=1;i<=n;i++) read(a[i]),c[max(i-r,1)]+=a[i],c[min(i+r,n)+1]-=a[i],ri+=a[i]+K;
	while(le<=ri) {ll md=(le+ri)>>1;if(chk(md)) le=md+1,rs=md;else ri=md-1;}
	return printf("%lld\n",rs),0;
}