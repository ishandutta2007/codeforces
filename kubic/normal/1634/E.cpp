#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define M 1000005
#define LIM 1000005
#define pb push_back
#define set(a,vl) memset(a,vl,sizeof(a))
#define cpy(x,y) memcpy(x,y,sizeof(x))
//#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
#define gc getchar
char *P1,*P2,buf[LIM];
int n,m,ds[N],dg[N],st[N];char ans[N];bool vs[N],tg[N];
vector<int> a[N];
int cntE,hd[N],cur[N];struct Edge {int v,w,id,nxt;}e[M];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
void addE(int u,int v,int w,int id)
{
	e[cntE]=(Edge) {v,w,id,hd[u]};hd[u]=cntE++;
	e[cntE]=(Edge) {u,0,id,hd[v]};hd[v]=cntE++;
}
void dfs(int u)
{
	for(int i=cur[u],v;~i;i=cur[u])
	{
		v=e[i].v;cur[u]=e[i].nxt;if(vs[i]) continue;
		vs[i]=vs[i^1]=1;dfs(v),st[++st[0]]=i;
	}
}
int main()
{
	n=rd();set(hd,-1);
	for(int i=1,x;i<=n;++i)
	{m=rd();for(int j=1;j<=m;++j) x=rd(),ds[++ds[0]]=x,a[i].pb(x);}
	sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1,t;i<=n;++i) for(int j=0;j<a[i].size();++j)
	{
		t=lower_bound(ds+1,ds+ds[0]+1,a[i][j])-ds;
		++dg[i];++dg[n+t];addE(i,n+t,1,j+1);
	}for(int i=1;i<=n+ds[0];++i) if(dg[i]&1) {puts("NO");return 0;}
	cpy(cur,hd);for(int i=1;i<=n+ds[0];++i) if(~cur[i]) dfs(i);
	for(int i=1;i<=st[0];i+=2) tg[st[i]]=tg[st[i]^1]=1;puts("YES");
	for(int i=1;i<=n;++i,puts(""))
	{
		for(int j=1;j<=a[i].size();++j) ans[j]='R';
		for(int j=hd[i];~j;j=e[j].nxt) if(tg[j]) ans[e[j].id]='L';
		for(int j=1;j<=a[i].size();++j) putchar(ans[j]);
	}return 0;
}