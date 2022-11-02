//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int a,b;bool operator<(node x) const {return b>x.b;}}a[105];
int n,sa,sb,f[10005][105],rs;
int main()
{
	read(n),sa=sb=0,memset(f,~0x3f,sizeof(f)),rs=f[0][0],f[0][0]=0;
	for(int i=1;i<=n;i++) read(a[i].a),sa+=a[i].a;
	for(int i=1;i<=n;i++) read(a[i].b);
	sort(a+1,a+n+1);int K=0;while(sb<sa) sb+=a[++K].b;
	for(int i=1;i<=n;i++) for(int j=sb;j>=a[i].b;j--) for(int k=1;k<=K;k++) f[j][k]=max(f[j][k],f[j-a[i].b][k-1]+a[i].a);
	for(int i=sa;i<=sb;i++) rs=max(rs,f[i][K]);
	return printf("%d %d\n",K,sa-rs),0;
}