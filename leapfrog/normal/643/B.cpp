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
int n,K,a,b,c,d;char vs[1005];
int main()
{
	read(n,K,a,b,c,d);if(n<=4||K<n+1) return puts("-1"),0;
	printf("%d %d ",a,c),vs[a]=vs[b]=vs[c]=vs[d]=1;
	for(int i=1;i<=n;i++) if(!vs[i]) printf("%d ",i);
	printf("%d %d\n",d,b),printf("%d %d ",c,a);
	for(int i=1;i<=n;i++) if(!vs[i]) printf("%d ",i);
	return printf("%d %d\n",b,d),0;
}