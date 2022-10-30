//Coded by leapfrog {{{
//Gened on 2021.10.25
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
const int N=200005;
int n,a[N],bt[35];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	memset(bt,0,sizeof(bt));
	for(int k=0;k<=30;k++) for(int i=1;i<=n;i++) bt[k]+=(a[i]>>k)&1;
	for(int i=1;i<=n;i++)
	{
		char fg=0;for(int j=0;j<=30;j++) if(bt[j]%i) fg=1;
		if(!fg) printf("%d ",i);
	}putchar('\n');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}