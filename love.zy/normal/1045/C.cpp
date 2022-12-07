#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
const int maxn=100005;
int n,m,q,pre[maxn],tot,clk,id[maxn],dep[maxn*12],gra[21][maxn*12],dis[maxn*12];
vector<int>G[maxn*12],bel[maxn];
struct Edge {
	int u,v;
	Edge(int u=0,int v=0):u(u),v(v){}
};
stack<Edge>stk;
inline int tarjan(int u,int f) {
	int lowu=++clk,lowv;
	pre[u]=lowu;
	int ch=0;
	for(int i=0;i<(int)G[u].size();++i) {
		int v=G[u][i];
//		cout<<"!!!"<<u<<" -> "<<v<<endl;
		Edge e=Edge(u,v);
		if(!pre[v]) {
			stk.push(e),++ch,lowv=tarjan(v,u),lowu=min(lowu,lowv);
			if(lowv>=pre[u]) {
				++tot;
				while(1) {
					Edge x=stk.top();stk.pop();
					int a=x.u,b=x.v;
//					cout<<"!!! Get:"<<a<<" -> "<<b<<endl;
					if(!bel[a].size()||bel[a].back()!=tot)
						bel[a].push_back(tot);
					if(!bel[b].size()||bel[b].back()!=tot)
						bel[b].push_back(tot);
					if(a==u&&b==v)
						break;
				}
			}
		}
		else if(pre[v]<pre[u]&&v!=f)
			stk.push(e),lowu=min(lowu,pre[v]);
	}
	return lowu;
}
inline void dfs(int u,int fa) {
	for(int j=1;j<21;++j)
		gra[j][u]=gra[j-1][gra[j-1][u]];
	for(int i=0;i<(int)G[u].size();++i) {
		int v=G[u][i];
		if(v==fa)
			continue;
//		cout<<"!!!"<<u<<" -> "<<v<<endl;
		dep[v]=dep[u]+1;
		dis[v]+=dis[u];
		gra[0][v]=u;
		dfs(v,u);
	}
}
inline int lca(int u,int v) {
	if(dep[u]<dep[v])
		swap(u,v);
	for(int d=dep[u]-dep[v],i=20;~i;--i)
		if(d>>i&1)
			u=gra[i][u];
	if(u==v)
		return u;
	for(int i=20;~i;--i)
		if(gra[i][u]!=gra[i][v])
			u=gra[i][u],v=gra[i][v];
	return gra[0][u];
}
int main() {
	read(n),read(m),read(q);
	for(int i=0,x,y;i<m;++i)
		read(x),read(y),G[x].push_back(y),G[y].push_back(x);
	for(int i=1;i<=n;++i)
		if(!pre[i])
			tarjan(i,-1);
//	cout<<"Total cnt:"<<tot<<endl;
//	for(int i=1;i<=n;++i) {
//		cout<<"Vertex "<<i<<":"<<endl;
//		for(int j=0;j<(int)bel[i].size();++j)
//			cout<<bel[i][j]<<" ";
//		cout<<endl;
//	}
	for(int i=1;i<=n;++i)
		G[i].clear();
	int cnt=n;
	for(int i=1;i<=tot;++i)
		id[i]=++cnt,dis[cnt]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<(int)bel[i].size();++j)
			G[i].push_back(id[bel[i][j]]),G[id[bel[i][j]]].push_back(i);
	dfs(1,0);
//	for(int i=1;i<=cnt;++i)
//		cout<<dis[i]<<" ";
//	cout<<endl;
	for(int x,y,l;q--;read(x),read(y),l=lca(x,y),printf("%d\n",dis[x]+dis[y]-2*dis[l]+(l>n)));
}