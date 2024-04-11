//Coded by Kamiyama_Shiki on 2021.11.17 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
inline void solve()
{
	int a,b;read(a,b);
	printf("%d\n",(24-a)*60-b);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}