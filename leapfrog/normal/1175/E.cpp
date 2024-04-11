//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,m,nx[500005][23];
int main()
{
	read(n),read(m);for(int i=0;i<=500000;i++) nx[i][0]=i;
	for(int i=1,l,r;i<=n;i++) read(l),read(r),nx[l][0]=max(nx[l][0],r);
	for(int i=0;i<=500000;i++) nx[i][0]=max(nx[i][0],nx[i-1][0]);
	for(int i=1;i<23;i++) for(int j=0;j<=500000;j++) nx[j][i]=nx[nx[j][i-1]][i-1];
	for(int l,r;m--;)
	{
		read(l),read(r);int cnt=0;
		for(int i=22;~i;i--) if(nx[l][i]<r) l=nx[l][i],cnt+=1<<i;
		if(nx[l][0]<r) puts("-1");else printf("%d\n",cnt+1);
	}
	return 0;
}