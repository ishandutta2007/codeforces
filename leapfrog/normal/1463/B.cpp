//
#include<bits/stdc++.h>
using namespace std;typedef unsigned int ui;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
int T,n,a[255],pw[105];long long sm=0;
int main()
{
	pw[0]=1;for(int i=1;i<=31;i++) pw[i]=pw[i-1]<<1;
	for(read(T);T--;putchar('\n')) {read(n);for(int i=1,w;i<=n;i++) read(w),printf("%d ",pw[upper_bound(pw+1,pw+31+1,w)-pw-1]);}
	return 0;
}