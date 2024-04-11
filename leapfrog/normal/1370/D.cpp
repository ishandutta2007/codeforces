//Coded by leapfrog on 2021.10.29 {{{
//
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
inline int solve(int lim)
{
	int cn=0;for(int i=1;i<=n;i++) if(cn&1) cn+=a[i]<=lim;else cn++;
	int vl=0;for(int i=1;i<=n;i++) if(vl&1) vl++;else vl+=a[i]<=lim;
	return max(cn,vl);
}
int main()
{
	read(n,K);for(int i=1;i<=n;i++) read(a[i]);
	int rs=1e9;for(int l=1,r=1e9,md=(l+r)>>1;l<=r;md=(l+r)>>1)
		if(solve(md)>=K) rs=md,r=md-1;else l=md+1;
	return printf("%d\n",rs),0;
}