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
template<typename T>inline void chkmn(T &a,T b) {a>b?a=b:a;}
template<typename T,typename...L>inline void chkmn(T &a,T b,L...l) {chkmn(a,b),chkmn(a,l...);}
template<typename T>inline void chkmx(T &a,T b) {a<b?a=b:a;}
template<typename T,typename...L>inline void chkmx(T &a,T b,L...l) {chkmx(a,b),chkmx(a,l...);}
const int N=100005;ll L1,L2,L3,L4,R1,R2,R3,R4;
int n;ll X[N],Y[N],Z[N],rsx,rsy,rsz;
inline ll flr(ll x,char bit) {return x-((x^bit)&1);}
inline ll cel(ll x,char bit) {return x+((x^bit)&1);}
inline char chk(ll vl)
{
	for(char i=0;i<2;i++)
	{
		ll l=flr(L1-vl,i),l1=flr(L2-vl,i),l2=flr(L3-vl,i),l3=flr(L4-vl,i);
		ll r=cel(R1+vl,i),r1=cel(R2+vl,i),r2=cel(R3+vl,i),r3=cel(R4+vl,i);
		//printf("%lld : %lld %lld %lld %lld ; %lld %lld %lld %lld\n",vl,l,l1,l2,l3,r,r1,r2,r3);
		if(l1>r1||l2>r2||l3>r3||l>r||l1+l2+l3>r||r1+r2+r3<l) continue;
		if(l1+l2+l3<l) l1=min(r1,l-l2-l3);
		if(l1+l2+l3<l) l2=min(r2,l-l1-l3);
		if(l1+l2+l3<l) l3=min(r3,l-l1-l2);
		if(l1+l2+l3>=l) return rsx=(l1+l2)/2,rsy=(l1+l3)/2,rsz=(l2+l3)/2,1;
	}return 0;
}
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(X[i],Y[i],Z[i]);
	L1=L2=L3=L4=-4e18,R1=R2=R3=R4=4e18;
	for(int i=1;i<=n;i++)
		chkmx(L1,X[i]+Y[i]+Z[i]),chkmn(R1,X[i]+Y[i]+Z[i]),
		chkmx(L2,X[i]+Y[i]-Z[i]),chkmn(R2,X[i]+Y[i]-Z[i]),
		chkmx(L3,X[i]-Y[i]+Z[i]),chkmn(R3,X[i]-Y[i]+Z[i]),
		chkmx(L4,Y[i]-X[i]+Z[i]),chkmn(R4,Y[i]-X[i]+Z[i]);
	//printf("%lld %lld %lld %lld ; %lld %lld %lld %lld\n",L1,L2,L3,L4,R1,R2,R3,R4);
	for(ll l=-1,r=4e18,md=(l+r)>>1;l<=r;md=(l+r)>>1) if(chk(md)) r=md-1;else l=md+1;
	printf("%lld %lld %lld\n",rsx,rsy,rsz);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}