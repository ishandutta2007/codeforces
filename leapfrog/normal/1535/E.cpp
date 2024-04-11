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
const int N=1000005;int fa[N][20],a[N],c[N],n;
inline int fnd(int x) {for(int i=19;~i;i--) if(a[fa[x][i]]) x=fa[x][i];return x;}
int main()
{
	read(n,a[1],c[1]);for(int g=2;g<=n+1;g++)
	{
		int fg,x,w;read(fg),read(x);
		if(fg&1)
		{
			read(a[g],c[g]),fa[g][0]=++x;
			for(int i=1;i<20;i++) fa[g][i]=fa[fa[g][i-1]][i-1];
		}else
		{
			read(w),x++;ll rs=0;int cnt=0;
			while(w&&a[x]) {int v=fnd(x),q=min(a[v],w);rs+=1ll*q*c[v],a[v]-=q,w-=q,cnt+=q;}
			printf("%d %lld\n",cnt,rs),fflush(stdout);
		}
	}
	return 0;
}