//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int r,g,n,sm,rs,f[200005];
int main()
{
	read(r),read(g),n=sqrt((r+g)<<1),f[0]=1,rs=0;
	while(1ll*n*(n+1)<=r+g+r+g) n++;
	for(int i=1;i<n;i++) for(int j=r;j>=i;j--) (f[j]+=f[j-i])%=P;
	sm=n*(n-1)/2;for(int i=0;i<=r;i++) if(sm-i<=g) (rs+=f[i])%=P;
	return printf("%d\n",rs),0;
}