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
const int N=400005;int n,a[N],b[N],qz[N],hz[N],fg[N],f[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i],b[i]);
	for(int i=1;i<=n;i++) if(a[i]<=n&&b[i]<=n) return puts("-1"),0;
	for(int i=1;i<=n;i++) fg[min(a[i],b[i])]=a[i]>b[i]&&(swap(a[i],b[i]),1),f[a[i]]=b[i];
	qz[0]=1e9;for(int i=1;i<=n;i++) qz[i]=min(qz[i-1],f[i]);
	for(int i=n;i>=1;i--) hz[i]=max(hz[i+1],f[i]);
	int ta=1e9,tb=1e9,sa=0,sb=0,ca=0,cb=0,rs=0;
	for(int i=1;i<=n;i++)
	{
		if(ta>tb) swap(ta,tb),swap(sa,sb),swap(ca,cb);
		if(f[i]<ta) ta=f[i],sa++,ca+=fg[i];
		else if(f[i]<tb) tb=f[i],sb++,cb+=fg[i];
		else return puts("-1"),0;
		if(qz[i]>hz[i+1]) rs+=min(ca+sb-cb,cb+sa-ca),ta=tb=1e9,sa=sb=ca=cb=0;
	}return printf("%d\n",rs),0;
}