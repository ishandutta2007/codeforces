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
const int N=100005;int n,m;char v[N];
inline void solve()
{
	read(n,m);for(int i=1;i<=n;i++) v[i]=0;
	for(int i=1,x,y,z;i<=m;i++) read(x,y,z),v[y]=1;
	for(int i=1;i<=n;i++) if(!v[i])
	{
		for(int j=1;j<=n;j++) if(j!=i) printf("%d %d\n",j,i);
		return;
	}
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}