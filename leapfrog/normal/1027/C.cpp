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
int Ca,n,a[1000005],b[1000005],bt=0;
inline void solve()
{
	read(n),bt=0;for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);for(int i=1;i<n;i++) if(a[i]==a[i+1]) b[++bt]=a[i],i++;
	int rx=-1,ry=-1;double rs=1e9;for(int i=1;i<bt;i++) if(rs>=1.0*b[i+1]/b[i]) rs=1.0*b[i+1]/b[i],rx=b[i],ry=b[i+1];
	printf("%d %d %d %d\n",rx,rx,ry,ry);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}