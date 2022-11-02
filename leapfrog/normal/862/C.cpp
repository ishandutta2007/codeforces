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
int a[100005];
int main()
{
	int n,x;read(n,x);if(n==2&&!x) return puts("NO"),0;
	puts("YES");if(n==1) return printf("%d\n",x),0;
	for(int i=1;i<n-1;i++) a[i]=i,x^=i;
	if(!x) a[n]=x,a[n-1]^=1<<18,a[n-2]^=1<<18|1<<19,a[n]^=1<<19;
	else a[n]=x,a[n]^=1<<18,a[n-1]^=1<<18;
	for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}