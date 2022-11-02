//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}int Ca;
int n,a[505],ch[505][505];const int dx[3]={1,0,-1},dy[3]={0,-1,0};
int tp,sx[250005],sy[2500005];
inline char chk(int i,int j) {return i>=1&&i<=n&&j>=1&&j<=i;}
inline void dfs(int x,int y,int w)
{
	tp=1,sx[tp]=x,sy[tp]=y;int id=w;
	while(w&&tp)
	{
		int x=sx[tp],y=sy[tp];tp--,w--,ch[x][y]=id;
		for(int i=2;~i;i--)
		{
			int tx=x+dx[i],ty=y+dy[i];if(!chk(tx,ty)) continue;
			if(!ch[tx][ty]) sx[++tp]=tx,sy[tp]=ty;
		}
	}
}
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ch[i][j]=0;
	for(int i=n;i;i--) dfs(i,i,a[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) printf("%d%c",ch[i][j],j==i?'\n':' ');
}
int main() {return solve(),0;}