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
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int n,m,cl[250005],vv[505][505];char ch[505][505];
struct edge{int to,nxt;}e[500005];int et,head[250005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
#define ID(i,j) ((i-1)*m+(j))
inline void dfs(int x)
{
	for(int i=head[x];i;i=e[i].nxt)
		if(!~cl[e[i].to]) cl[e[i].to]=cl[x]^1,dfs(e[i].to);
		else if(!(cl[x]^cl[e[i].to])) puts("NO"),exit(0);
}
int main()
{
	read(n,m);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(ch[i][j]=='X')
	{
		vector<int>v;int cnt=0;for(int k=0;k<4;k++)
		{
			int nx=i+dx[k],ny=j+dy[k];
			if(nx<1||nx>n||ny<1||ny>m) continue;
			if(ch[nx][ny]=='.') cnt++,v.push_back(ID(nx,ny));
		}
		if(cnt&1) return puts("NO"),0;else vv[i][j]=cnt/2*5;
		for(int i=0;i<(int)v.size();i+=2) adde(v[i],v[i+1]),adde(v[i+1],v[i]);
	}
	memset(cl,-1,sizeof(cl));for(int i=1;i<=n*m;i++) if(!~cl[i]) cl[i]=0,dfs(i);
	puts("YES");for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		printf("%d%c",ch[i][j]=='X'?vv[i][j]:cl[ID(i,j)]?4:1,j==m?'\n':' ');
	return 0;
}