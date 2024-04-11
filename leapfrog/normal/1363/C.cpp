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
int T,n,X;
int main()
{
	for(read(T);T--;)
	{
		read(n),read(X);int deg=0;if(n==1) {puts("Ayush");continue;}
		for(int i=1,x,y;i<n;i++) read(x),read(y),deg+=x==X,deg+=y==X;
		if(deg==1) puts("Ayush");else if(n&1) puts("Ashish");else puts("Ayush");
	}
	return 0;
}