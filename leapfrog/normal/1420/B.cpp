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
const int N=100005;int n,a[N],bt[50];
inline void solve()
{
	read(n),memset(bt,0,sizeof(bt));ll rs=0;
	for(int i=1,x;i<=n;i++) {read(x);for(int i=30;~i;i--) if((x>>i)&1) {bt[i]++;break;}}
	for(int i=30;~i;i--) rs+=1ll*bt[i]*(bt[i]-1)/2;
	printf("%lld\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}