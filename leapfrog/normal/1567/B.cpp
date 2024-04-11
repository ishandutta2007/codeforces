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
int xr[1000005];
inline void solve()
{
	int a,b;read(a,b);int rs=a;b^=xr[a-1];
	if(b==0) printf("%d\n",rs);else if(b==a) printf("%d\n",rs+2);else printf("%d\n",rs+1);
}
int main()
{
	for(int i=1;i<=300000;i++) xr[i]=xr[i-1]^i;
	int Ca;for(read(Ca);Ca--;) solve();return 0;
}