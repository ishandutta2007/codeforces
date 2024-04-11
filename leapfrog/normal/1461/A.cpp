//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int T,n,K;
int main()
{
	for(read(T);T--;putchar('\n'))
	{
		read(n),read(K);
		for(int i=1;i<=n;i++) putchar((i-1)%3+'a');
	}
}