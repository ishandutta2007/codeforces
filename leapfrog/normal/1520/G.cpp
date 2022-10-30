//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int n,m,W,a[2005][2005],ds[2][2005][2005];
struct node{int x,y,st;};
inline void solve(int id,int x,int y)
{
	queue<node>q;ds[id][x][y]=0,q.push((node){x,y,0});
	while(!q.empty())
	{
		node x=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=x.x+dx[i],ny=x.y+dy[i],nst=x.st+1;
			if(nx<1||ny<1||nx>n||ny>m||a[nx][ny]==-1) continue;
			if(nst<ds[id][nx][ny]) ds[id][nx][ny]=nst,q.push((node){nx,ny,nst});
		}
	}
}
int main()
{
	read(n),read(m),read(W);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
	memset(ds,0x3f,sizeof(ds)),solve(0,1,1),solve(1,n,m);
	ll res=1ll*ds[0][n][m]*W,mn1=1e18,mn2=1e18;if(ds[0][n][m]>=1e9) res=1e18;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]>0&&ds[0][i][j]<=1e9) mn1=min(mn1,1ll*ds[0][i][j]*W+a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]>0&&ds[1][i][j]<=1e9) mn2=min(mn2,1ll*ds[1][i][j]*W+a[i][j]);
	return res=min(res,mn1+mn2),printf("%lld\n",res>=1e17?-1:res),0;
}