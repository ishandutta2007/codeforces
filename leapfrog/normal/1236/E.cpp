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
const int N=100005;int n,m,f[(N<<1)+10],a[N];ll rs=0;
int main()
{
	read(n,m);for(int i=1;i<=m;i++) read(a[i]);
	if(n==1) return puts("0"),0;
	for(int i=m;i>=1;i--) f[i+a[i]]=f[i+a[i]+1]+1;
	//for(int i=1;i<=n;i++) printf("%d%c",f[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++) rs-=max(1,i-m-1+f[i]);
	memset(f,0,sizeof(f));
	for(int i=m;i>=1;i--) f[a[i]-i+N]=f[a[i]-i+N-1]+1;
	//for(int i=1;i<=n;i++) printf("%d%c",f[i+N],i==n?'\n':' ');
	for(int i=1;i<=n;i++) rs+=min(n,i+m-f[i+N]+1);
	return printf("%lld\n",rs+n),0;
}