#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,dep,lef,a[200005],b[200005],f[200005];
int main()
{
	read(n),read(dep),read(lef),dep++,a[1]=1;if(lef-1>n-dep) return puts("-1"),0;
	for(int i=2;i<=dep;i++) read(a[i]);
	for(int i=1;i<=dep;i++) f[i]=min(a[i],a[i+1]),lef-=a[i]-f[i];
	int zk;if(lef<0) return puts("-1");
	for(int i=dep-1;i>1;i--) zk=min(f[i]-1,lef),lef-=zk,f[i]-=zk;
	printf("%d\n",n);int gg=1;
	for(int i=2;i<=dep;i++) {for(int j=0;j<a[i];j++) printf("%d %d\n",gg+j%f[i-1],gg+a[i-1]+j);gg+=a[i-1];}
	return 0;
}