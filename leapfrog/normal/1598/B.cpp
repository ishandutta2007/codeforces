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
const int N=1005;int n,a[N][10];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) read(a[i][j]);
	for(int i=1;i<=5;i++) for(int j=i+1;j<=5;j++)
	{
		int c1=0;for(int k=1;k<=n;k++) c1+=a[k][i];
		int c2=0;for(int k=1;k<=n;k++) c2+=a[k][j];
		int c3=0;for(int k=1;k<=n;k++) c3+=a[k][i]&a[k][j];
		if(c1+c2-c3<n) continue;
		if(c1>=n/2&&c2>=n/2) return puts("YES"),void();
	}puts("NO");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}