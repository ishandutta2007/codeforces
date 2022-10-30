//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,a[100005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	char fg=1;for(int i=1;i<=n;i++) fg&=a[i];
	if(fg==1)
	{
		printf("%d ",n+1);
		for(int i=1;i<=n;i++) printf("%d%c",i,i==n?'\n':' ');
		return;
	}else fg=0;
	for(int i=1;i<=n;i++) fg|=a[i];
	if(!fg)
	{
		for(int i=1;i<=n;i++) printf("%d ",i);
		printf("%d\n",n+1);
		return;
	}
	int wh=0;for(int i=1;i<n;i++) if(a[i]==0&&a[i+1]==1) {wh=i;break;}
	for(int i=1;i<=wh;i++) printf("%d ",i);
	printf("%d ",n+1);for(int i=wh+1;i<=n;i++) printf("%d ",i);
	putchar('\n');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}