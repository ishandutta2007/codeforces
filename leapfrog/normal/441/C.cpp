//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,k,cnt,a[90005],b[90005];
int main()
{
	read(n),read(m),read(k),cnt=0;
	for(int i=1;i<n;i+=2)
	{
		for(int j=1;j<=m;j++) a[++cnt]=i,b[cnt]=j;
		for(int j=m;j>=1;j--) a[++cnt]=i+1,b[cnt]=j;
	}
	if(n&1) for(int j=1;j<=m;j++) a[++cnt]=n,b[cnt]=j;
	for(int i=1;i<k;i++) printf("2 %d %d %d %d\n",a[(i<<1)-1],b[(i<<1)-1],a[i<<1],b[i<<1]);
	printf("%d ",cnt-((k-1)<<1));for(int i=(k-1)<<1|1;i<=cnt;i++) printf("%d %d ",a[i],b[i]);
	return puts(""),0;
}