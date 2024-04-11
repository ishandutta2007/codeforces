//
//
#include<bits/stdc++.h>
using namespace std;const int P=(1<<22)-1;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,f[P+5],a[1000005];
int main()
{
	read(n),memset(f,-1,sizeof(f));for(int i=1;i<=n;i++) read(a[i]),f[a[i]]=a[i];
	for(int i=1;i<=P;i++) if(f[i]!=-1) for(int j=0;j<22;j++) if(!((i>>j)&1)) f[i^(1<<j)]=f[i];
	for(int i=1;i<=n;i++) printf("%d%c",f[P^a[i]],i==n?'\n':' ');
	return 0;
}