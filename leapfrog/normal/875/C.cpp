//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
struct edge{int to,nxt;}e[400005];int n,m,et,head[200005];
int buf[200005],*a[100005],ln[100005],tt,st[200005],tp;
int dfn[200005],dt,low[200005],cl[200005],ct;char v[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void add(int x,int y)
{//xx+mx<y
	if(x<y) adde(x+m,y+m),adde(y,x);
	if(x>y) adde(x+m,x),adde(y,y+m);
}
inline void tarjan(int x)
{
	dfn[x]=low[x]=++dt,v[x]=1,st[++tp]=x;
	for(int i=head[x];i;i=e[i].nxt)
		if(!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[e[i].to],low[x]);
		else if(v[e[i].to]) low[x]=min(dfn[e[i].to],low[x]);
	if(dfn[x]==low[x]) {int y=++ct;do v[y=st[tp--]]=0,cl[y]=ct;while(y^x);}
}
int main()
{
	read(n),read(m),a[1]=buf;for(int i=1;i<=n;i++)
	{
		read(ln[i]),a[i+1]=a[i]+ln[i];
		for(int j=1;j<=ln[i];j++) read(a[i][j]);
	}
	for(int i=2;i<=n;i++)
	{
		char fg=1;for(int j=1;j<=ln[i]&&j<=ln[i-1]&&fg;j++)
			if(a[i][j]^a[i-1][j]) add(a[i-1][j],a[i][j]),fg=0;
		if(fg&&ln[i]<ln[i-1]) return puts("No"),0;
	}
	for(int i=1;i<=m+m;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=m;i++) if(cl[i]==cl[i+m]) return puts("No"),0;
	int cnt=0;puts("Yes");for(int i=1;i<=m;i++) if(cl[i]<cl[i+m]) cnt++;
	printf("%d\n",cnt);for(int i=1;i<=m;i++) if(cl[i]<cl[i+m]) printf("%d ",i);
	return putchar('\n'),0;
}