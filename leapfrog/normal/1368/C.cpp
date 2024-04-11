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
int main()
{
	int n;read(n),printf("%d\n1 1\n",n*3+4);
	for(int i=1;i<=n+1;i++) printf("%d %d\n%d %d\n%d %d\n",i+1,i,i,i+1,i+1,i+1);
	return 0;
}