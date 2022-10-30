//Coded by leapfrog {{{
//Coded on 2021.10.26
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
int n,m,b[105];ll a[105],rfs,rsc;
int main()
{
	read(n,m);for(int i=1;i<=n;i++) read(a[i]);
	for(int S=2;S<=m+m;S++)
	{
		for(int i=1;i<=n;i++) b[i]=a[i]%S;
		b[n+1]=0,b[n+2]=S-1,sort(b+1,b+n+3);
		for(int i=n+2;i>1;i--)
		{
			int fg=(n+2-i)&1,l=max(b[i-1],b[n+!fg]/2)+1,r=min(b[i],m);
			(fg?rfs:rsc)+=max(min(r,S-l)-max(l,S-r)+1,0);
		}
	}
	ll rs=(1ll*m*m-rfs-rsc)>>1;
	return printf("%lld %lld %lld %lld\n",rs,rs,rfs,rsc),0;
}