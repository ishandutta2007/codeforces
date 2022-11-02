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
int T,n,a[200005],cf[200005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),cf[i]=0;
	for(int i=1;i<=n;i++) cf[max(1,i-a[i]+1)]++,cf[i+1]--;
	for(int i=1;i<=n;i++) cf[i]+=cf[i-1];
	for(int i=1;i<=n;i++) printf("%d%c",!!cf[i],i==n?'\n':' ');
}
int main() {for(read(T);T--;) solve();return 0;}