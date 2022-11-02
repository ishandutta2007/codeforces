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
int n,m,a[300005],b[300005],cn[300005],rs[6],rst,v[300005];
inline char chk(int x)
{
	for(int i=1;i<=n;i++) b[i]=a[(i+x-1)%n+1],v[i]=0;
	//for(int i=1;i<=n;i++) printf("%d%c",b[i],i==n?'\n':' ');
	int tt=0;for(int i=1;i<=n;i++) if(b[i]!=i) tt++;
	for(int i=1;i<=n;i++) if(b[i]!=i&&!v[i]) {v[i]=1,tt--;for(int j=b[i];j^i;j=b[j]) v[j]=1;}
	if(tt<=m) return 1;else return 0;
}
inline void solve()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]),cn[i-1]=0;
	for(int i=1;i<=n;i++) cn[(i-a[i]+n)%n]++;
	rst=0;for(int i=0;i<n;i++) if(cn[i]>=n-m*2&&chk(i)) rs[++rst]=i;
	printf("%d ",rst);for(int i=1;i<=rst;i++) printf("%d%c",rs[i],i==rst?'\n':' ');
	if(rst==0) putchar('\n');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}