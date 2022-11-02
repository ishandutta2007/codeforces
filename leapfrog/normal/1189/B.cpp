//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,a[100005],b[100005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);for(int i=1;i<=n;i+=2) b[(i+1)>>1]=a[i];
	for(int i=2;i<=n;i+=2) b[n-(i>>1)+1]=a[i];
	for(int i=1;i<=n;i++) if(b[i]+b[(i+1)%n+1]<=b[i%n+1]) return puts("NO"),0;
	puts("YES");for(int i=1;i<=n;i++) printf("%d%c",b[i],i==n?'\n':' ');
	return 0;
}