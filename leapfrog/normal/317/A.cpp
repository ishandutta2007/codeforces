//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
long long x,y,m;
int main()
{
	read(x),read(y),read(m);long long tot=0;if(x>y) swap(x,y);
	if(x>=m||y>=m) return puts("0"),0;else if(x<=0&&y<=0) return puts("-1"),0;
	if(x<0) tot+=(-x)/y,x+=(-x)/y*y;
	for(;x<m&&y<m;) {if(x>y) swap(x,y);x+=y,++tot;}
	return printf("%lld\n",tot),0;
}