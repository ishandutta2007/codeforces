//Coded by leapfrog on 2021.10.27 {{{
//
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
const int N=2005;int n,a[N][N],tn[N];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[0][i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) tn[j]=0;
		for(int j=1;j<=n;j++) tn[a[i-1][j]]++;
		for(int j=1;j<=n;j++) a[i][j]=tn[a[i-1][j]];
	}int q;read(q);
	for(int x,k;q--;) read(x,k),printf("%d\n",a[min(k,n)][x]);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}