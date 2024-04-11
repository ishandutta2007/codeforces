//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,k,a[1000005];
int main()
{
	read(n),read(k);int res=1e9,tag=1;
	for(int i=1;i<=n;i++) read(a[i]),res=min(res,a[i]);
	while(tag) {tag=0;for(int i=1;i<=n;i++) while(a[i]%res>k) res--,tag=1;}
	return printf("%d\n",res),0;
}