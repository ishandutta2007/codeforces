//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=105;int n,a[N];
inline char chk(int x) {for(int i=2;i*i<=x;i++) if(x%i==0) return 0;return 1;}
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int sm=0;for(int i=1;i<=n;i++) sm+=a[i];
	if(!chk(sm)) {printf("%d\n",n);for(int i=1;i<=n;i++) printf("%d%c",i,i==n?'\n':' ');return;}
	for(int i=1;i<=n;i++) if(!chk(sm-a[i]))
	{
		printf("%d\n",n-1);
		for(int j=1;j<=n;j++) if(j!=i) printf("%d ",j);
		putchar('\n');return;
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(!chk(sm-a[i]-a[j]))
	{
		printf("%d\n",n-2);
		for(int k=1;k<=n;k++) if(k!=i&&k!=j) printf("%d ",k);
		putchar('\n');return;
	}
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}