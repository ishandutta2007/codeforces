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
int a[100005],vs[100005];
int main()
{
	int n,p;read(n,p),a[0]=n+1;
	for(int i=1;i<=p;i++) a[i]=(i&1?(i+1)>>1:n+1-(i>>1)),printf("%d ",a[i]);
	if(a[p]>a[p-1]) for(int i=a[p]-1;i>a[p-1];i--) printf("%d ",i);
	else for(int i=a[p]+1;i<a[p-1];i++) printf("%d ",i);
	return putchar('\n'),0;
}