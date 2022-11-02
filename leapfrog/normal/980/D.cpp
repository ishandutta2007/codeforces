//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n=1e4,tt=0,a[10005],rs[10005],t[10005];char v[10005];
inline void chk(int &a)
{
	int fg=1;if(a<0) fg=0,a=-a;
	for(int i=2;i*i<=a;i++) while(a%(i*i)==0) a/=i,a/=i;
	if(!fg) a=-a;
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),chk(a[i]),t[++tt]=a[i];
	sort(t+1,t+tt+1),tt=unique(t+1,t+tt+1)-t-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(t+1,t+tt+1,a[i])-t;
//	for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
//	for(int i=1;i<=n;i++) printf("%d%c",t[a[i]],i==n?'\n':' ');
	for(int i=1;i<=n;i++)
	{
		int res=0;memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++) if(t[a[j]]) res+=!v[a[j]],v[a[j]]=1,rs[res]++;else rs[max(res,1)]++;
	}
	for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	return 0;
}