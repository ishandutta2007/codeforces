//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[200005],cn[200005],zs,mx,buf[400005],*tim;
inline void solve(int cl)
{
	memset(buf,-1,sizeof(buf));if(cl==zs) return;else tim[0]=0;
	for(int i=1,w=0;i<=n;i++)
	{
		if(a[i]==zs) w--;else if(a[i]==cl) w++;
		if(~tim[w]) mx=max(mx,i-tim[w]);else tim[w]=i;
	}
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),cn[a[i]]++;
	for(int i=1;i<=n;i++) if(cn[zs]<cn[i]) zs=i;
	tim=buf+200001;for(int i=1;i<=100&&i<=n;i++) solve(i);
	return printf("%d\n",mx),0;
}