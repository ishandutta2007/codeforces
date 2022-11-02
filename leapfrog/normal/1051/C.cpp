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
const int N=105;int n,a[105],cn[105],ps[105],rs[105];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),cn[a[i]]++,ps[a[i]]=i;
	int cc=0,ff=0;for(int i=1;i<=100;i++) cc+=cn[i]==1,(cn[i]>2?ff=ps[i]:0);
	for(int i=1,gg=1;i<=100;i++) if(cn[i]==1) rs[ps[i]]=(gg^=1);
	if(!ff&&cc&1) return puts("NO"),0;else puts("YES");
	cc&1?rs[ff]=1:0;for(int i=1;i<=n;i++) putchar('A'+rs[i]);
	return putchar('\n'),0;
}