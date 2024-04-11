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
int n,m,c[4000005],deg[4000005];char ch[2005][2005],vs[4000005];
inline int id(int x,int y) {return(x-1)*m+y;}
vector<pair<int,int> >rs;
inline void addr(int x,int y) {rs.push_back(make_pair(min(x,y),max(x,y)));}
struct edge{int to,nxt;}e[16000005];int et,head[4000005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,deg[x]++;}
inline void mrg(int x,int y)
{
	if(x^n&&ch[x][y]=='.'&&ch[x+1][y]=='.') adde(id(x,y),id(x+1,y)),adde(id(x+1,y),id(x,y));
	if(y^m&&ch[x][y]=='.'&&ch[x][y+1]=='.') adde(id(x,y),id(x,y+1)),adde(id(x,y+1),id(x,y));
}
int main()
{
	read(n,m);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) c[id(i,j)]=ch[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) mrg(i,j);
	queue<int>q;for(int i=1;i<=n*m;i++) if(deg[i]==1) q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();if(vs[x]) continue;
		int y=0;for(int i=head[x];i;i=e[i].nxt) if(!vs[e[i].to]) {y=e[i].to;break;}
		if(!y) return puts("Not unique"),0;else addr(x,y),vs[x]=vs[y]=1;
		for(int i=head[x];i;i=e[i].nxt) if(--deg[e[i].to]==1) q.push(e[i].to);
		for(int i=head[y];i;i=e[i].nxt) if(--deg[e[i].to]==1) q.push(e[i].to);
	}
	for(int i=1;i<=n*m;i++) if(c[i]=='.'&&!vs[i]) return puts("Not unique"),0;
	for(auto x:rs) if(x.first+1==x.second&&m!=1) c[x.first]='<',c[x.second]='>';else c[x.first]='^',c[x.second]='v';
	for(int i=1;i<=n;i++,putchar('\n')) for(int j=1;j<=m;j++) putchar(c[id(i,j)]);
	return 0;
}