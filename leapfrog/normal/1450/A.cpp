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
int T;char c[1000005];
int main()
{
	for(read(T);T--;)
	{
		int n;read(n),scanf("%s",c+1);
		sort(c+1,c+n+1),printf("%s\n",c+1);
	}
}