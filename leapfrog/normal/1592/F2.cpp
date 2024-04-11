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
int n,m,mt[505];char ch[505][505],fg[505][505],vs[505];
inline char dfs(int x)
{
	for(int y=1;y<m;y++) if(fg[x][y]&&fg[x][m]&&fg[n][y]&&!vs[y])
		{vs[y]=1;if(!mt[y]||dfs(mt[y])) return mt[y]=x,1;}
	return 0;
}
int main()
{
	read(n,m);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ch[i][j]=ch[i][j]=='B';
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) fg[i][j]=ch[i][j]^ch[i][j+1]^ch[i+1][j]^ch[i+1][j+1];
	int rs=0;for(int i=1;i<n;i++) memset(vs,0,sizeof(vs)),dfs(i);
	for(int j=1,i;j<m;j++) if(mt[j]) i=mt[j],fg[i][j]^=1,fg[i][m]^=1,fg[n][j]^=1,fg[n][m]^=1,rs+=2;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) rs+=fg[i][j];
	int sm=rs-1;if(fg[n][m]) for(int i=1;i<n;i++) for(int j=1;j<m;j++)
		{int vl=sm-fg[i][j]-fg[i][m]-fg[n][j],tp=3-fg[i][j]-fg[i][m]-fg[n][j];rs=min(rs,tp+vl+2);}
	return printf("%d\n",rs),0;
}