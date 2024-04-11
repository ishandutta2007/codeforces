//Coded by Kamiyama_Shiki on 2021.11.02 {{{
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
const int N=500005;int a[N],n;
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=2;i<=n;i++) if(a[i-1]<=a[i]) return puts("YES"),void();
	puts("NO");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}