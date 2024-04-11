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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n,a[100005];
inline char chk() {for(int i=2;i<=n;i++) if(a[i-1]>a[i]) return 1;return 0;}
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int rs=0;for(char fg=1;chk();fg^=1,rs++)
	{
		if(fg) {for(int i=1;i<n;i+=2) if(a[i]>a[i+1]) swap(a[i],a[i+1]);}
		else {for(int i=2;i<n;i+=2) if(a[i]>a[i+1]) swap(a[i],a[i+1]);}
		//for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	}
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}