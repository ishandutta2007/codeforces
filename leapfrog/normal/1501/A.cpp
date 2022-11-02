//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,a[100005],b[100005],tim[100005],T;
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),read(b[i]);
	int nw=0;for(int i=1;i<=n;i++) read(tim[i]);
	for(int i=1;i<=n;i++) {nw+=a[i]-b[i-1]+tim[i];if(i^n) nw=max(b[i],nw+(b[i]-a[i]+1)/2);}
	printf("%d\n",nw);
}
int main() {for(read(T);T--;) solve();return 0;}