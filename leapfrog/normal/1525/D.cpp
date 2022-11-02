//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,at,bt,a[5005],b[5005],f[5005][5005];
int main()
{
	read(n),memset(f,0x3f,sizeof(f)),memset(f[0],0,sizeof(f[0]));
	for(int i=1,x;i<=n;i++) read(x),(x?a:b)[++(x?at:bt)]=i;
	for(int i=1;i<=at;i++) for(int j=1;j<=bt;j++) f[i][j]=min(f[i][j-1],f[i-1][j-1]+abs(a[i]-b[j]));
	return printf("%d\n",f[at][bt]),0;
}