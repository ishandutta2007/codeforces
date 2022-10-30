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
inline char chk(int x) {int y=sqrt(x)+1e-8;return y*y==x;}
int main()
{
	int a,b,g;read(a,b),g=__gcd(a,b),a/=g,b/=g;if(a>b) swap(a,b);
	int x=-1,y;for(int i=1;i<g;i++) if(chk(g*g-i*i)) {x=i,y=sqrt(g*g-i*i)+1e-8;break;}
	if(!~x) return puts("NO"),0;else puts("YES");
	printf("%d %d\n%d %d\n%d %d\n",0,0,y*a,x*a,-x*b,y*b);
}