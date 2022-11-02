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
const int N=105;int n,a[N],b[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
	int cn=1;for(int i=1;i<=n;i++) cn+=a[i]<b[i];
	int fg=0;for(int i=1;i<=n;i++) fg+=a[i]>b[i];
	if(!fg) puts("-1");else printf("%d\n",(cn+fg-1)/fg);
}