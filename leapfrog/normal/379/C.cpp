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
const int N=300005;int n;
struct ${int id,w;}a[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].w),a[i].id=i;
	sort(a+1,a+n+1,[]($ a,$ b){return a.w<b.w;});
	for(int i=1;i<=n;i++) a[i].w=max(a[i-1].w+1,a[i].w);
	sort(a+1,a+n+1,[]($ a,$ b){return a.id<b.id;});
	for(int i=1;i<=n;i++) printf("%d%c",a[i].w,i==n?'\n':' ');
	return 0;
}