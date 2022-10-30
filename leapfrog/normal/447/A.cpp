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
int n,a[100005],p,hs[10005];
int main()
{
	read(p,n);for(int i=1,x;i<=n;i++)
		{read(x);if(hs[x%p]) return printf("%d\n",i),0;else hs[x%p]=1;}
	return puts("-1"),0;
}