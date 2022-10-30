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
int n,S,deg[5000005];
int main()
{
	read(n),read(S);
	for(int i=1,x,y;i<n;i++) read(x),read(y),deg[x]++,deg[y]++;
	int cnt=0;for(int i=1;i<=n;i++) cnt+=deg[i]==1;
	return printf("%.10lf\n",2.0*S/cnt),0;
}