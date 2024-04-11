#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,c[2005],v[2005];long long res,f[4005];
int main()
{
	read(n),memset(f,0x3f,sizeof(f)),m=0,f[0]=0,res=f[1];
	for(int i=1;i<=n;i++) read(c[i]),++c[i],read(v[i]),m=max(m,c[i]);
	for(int i=1;i<=n;i++) for(int j=m+n;j>=c[i];j--) f[j]=min(f[j],f[j-c[i]]+v[i]);
	for(int i=n;i<=n+m;i++) res=min(res,f[i]);
	return printf("%lld\n",res),0;
}