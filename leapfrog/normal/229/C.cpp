//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,deg[1000005];
inline long long C1(int x) {return x;}
inline long long C2(int x) {return 1ll*x*(x-1)/2;}
inline long long C3(int x) {return 1ll*x*(x-1)/2*(x-2)/3;}
int main()
{
	read(n),read(m);long long res=0,sm=C3(n);
	for(int i=1,x,y;i<=m;i++) read(x),read(y),deg[x]++,deg[y]++;
	for(int i=1;i<=n;i++) res+=deg[i]*(n-1-deg[i]);
	return printf("%lld\n",sm-(res>>1)),0;
}