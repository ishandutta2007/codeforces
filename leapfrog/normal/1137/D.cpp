//Coded by Kamiyama_Shiki on 2021.11.19 {{{
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
const int N=100005;
inline int ask() {int w;ll k;fflush(stdout),read(w);for(int j=1;j<=w;j++) read(k);return w;}
int main()
{
	while(1) {puts("next 0"),ask(),puts("next 0 1");if(ask()==2) break;}
	while(1) {puts("next 0 1 2 3 4 5 6 7 8 9");if(ask()==1) break;}
	return puts("done"),fflush(stdout),0;
}