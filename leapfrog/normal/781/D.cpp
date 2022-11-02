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
struct edge{int to,w,nxt;}e[500000];int et,head[505];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,head[x]},head[x]=et;}
int n,m;bitset<505>st[61][2][505],pre,now;
int main()
{
	read(n),read(m),memset(st,-1,sizeof(st));
	for(int d=0;d<61;d++) for(int i=1;i<=n;i++) st[d][0][i].reset(),st[d][1][i].reset();
	for(int i=1,x,y,w;i<=m;i++) read(x),read(y),read(w),st[0][w][x][y]=1;
	for(int d=1;d<61;d++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	{
		if(st[d-1][0][i][j]) st[d][0][i]|=st[d-1][1][j];
		if(st[d-1][1][i][j]) st[d][1][i]|=st[d-1][0][j];
	}
	//for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("(%d,%d)%c",(int)st[1][0][i][j],(int)st[1][1][i][j],j==n?'\n':' ');
	ll res=0;pre[1]=1;for(int d=61,qwq=0;~d;d--)
	{
		now.reset();for(int i=1;i<=n;i++) if(pre[i]) now|=st[d][qwq][i];
		if(now.count()) res|=1ll<<d,qwq^=1,pre=now;
	}
	return printf("%lld\n",res>=1e18?-1:res),0;
}