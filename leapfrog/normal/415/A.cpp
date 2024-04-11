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
int n,m,a[105];
int main()
{
	read(n),read(m);
	for(int i=1,x;i<=m;i++) {read(x);for(int j=x;j<=n;j++) if(a[j]) break;else a[j]=x;}
	for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}