//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}int Ca;
int n,a[100005];
inline char cmp(int a,int b) {return (a&1)<(b&1);}
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1,cmp);for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
}
int main() {for(read(Ca);Ca--;) solve();return 0;}