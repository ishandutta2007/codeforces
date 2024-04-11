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
struct ${int id,vl;char operator<($ b) const {return vl<b.vl;}}a[100005];
inline void solve()
{
	int n,rs=0;read(n);for(int i=1;i<=n;i++) read(a[i].vl),a[i].id=i;
	sort(a+1,a+n+1);for(int i=1;i<=n&&a[i].vl*a[i].vl<=n*2;i++)
		for(int j=i+1;j<=n;j++) rs+=a[i].vl*a[j].vl==a[i].id+a[j].id;
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}