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
int n,K;
int main()
{
	read(n,K);if(n/2>K) return puts("-1"),0;
	if(n==1) return puts(K?"-1":"1"),0;
	if(n/2==K) {for(int i=1;i<=n;i++) printf("%d%c",i,i==n?'\n':' ');return 0;}
	int v=K-n/2+1;printf("%d %d ",v,v*2);for(int i=1;i<=2*(n/2-1);i++) printf("%d ",v*2+i);
	if(n&1) return puts("1"),0;else return putchar('\n'),0;
}