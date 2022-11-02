//
#include<bits/stdc++.h>
#define ri register
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,G,a[300005],rs=1e9,pc,p[3000005],mp[3000005],ls[15000005],v[15000005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),G=__gcd(G,a[i]);
	for(int i=1;i<=n;i++) a[i]/=G;
	for(int i=2;i<=15000000;i++)
	{
		if(!v[i]) p[++pc]=i,ls[i]=i,v[i]=pc;
		for(int j=1;j<=pc&&p[j]*i<=15000000;j++) {v[i*p[j]]=1,ls[i*p[j]]=p[j];if(i%p[j]==0) break;}
	}
	for(ri int i=1,g;i<=n;i++) while(a[i]!=1) {mp[v[g=ls[a[i]]]]++;while(a[i]%g==0) a[i]/=g;}
	for(ri int i=1;i<=pc;i++) if(mp[i]!=n&&mp[i]) rs=min(rs,n-mp[i]);
	if(rs>n) return puts("-1"),0;else return printf("%d\n",rs),0;
}