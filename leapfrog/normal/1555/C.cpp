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
const int N=100005;int a[2][N],s[2][N],n;
inline void solve()
{
	read(n);for(int i=0;i<=1;i++) for(int j=1;j<=n;j++) read(a[i][j]);
	for(int i=0;i<=1;i++) for(int j=1;j<=n;j++) s[i][j]=s[i][j-1]+a[i][j];
	int rs=2e9;for(int i=1;i<=n;i++) rs=min(rs,max(s[0][n]-s[0][i],s[1][i-1]));
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}