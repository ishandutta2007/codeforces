//
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
int n,k;
int main()
{
	read(n),read(k),printf("%d\n",k*(6*n-1));
	for(int i=1,g;i<=n;i++) g=i*6-5,printf("%d %d %d %d\n",g*k,g*k+k,g*k+(k<<1),g*k+(k<<2));
	return 0;
}