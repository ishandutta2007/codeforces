#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

struct edge {
	int u,v;
	bool bridge;
};

int n,m,s,t;
vector<int> g[1024];
bool vis[1024];
int d[1024],b[1024],tt;
edge e[30005];
int c[30005];
vector<int> p,p2;

bool fp(int x, vector<int> &p){
	if(x==t)return true;
	if(vis[x])return false;
	vis[x]=true;
	fore(i,0,g[x].size()){
		int j=g[x][i];
		int y=e[j].u^e[j].v^x;
		if(fp(y,p)){
			p.pb(j);
			return true;
		}
	}
	return false;
}

void dfs(int u, int pe){
	b[u]=d[u]=tt++;
	fore(_,0,g[u].size()){
		int ne=g[u][_];
		if(ne==pe)continue;
		int v=e[ne].u^e[ne].v^u;
		if(d[v]<0){
			dfs(v,ne);
			if(b[v]>d[u])e[ne].bridge=true;
			b[u]=min(b[u],b[v]);
		}
		else if(d[v]<d[u])b[u]=min(b[u],d[v]);
	}
}

void bridges(){
	fore(i,0,m)e[i].bridge=false;
	memset(d,-1,sizeof(d));
	tt=0;
	fore(i,0,n)if(d[i]<0)dfs(i,-1);
}

pair<int,int> sol;
int res;

int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);s--;t--;
	fore(i,0,m){
		scanf("%d%d%d",&e[i].u,&e[i].v,c+i);
		e[i].u--;e[i].v--;
		g[e[i].u].pb(i);
		g[e[i].v].pb(i);
	}
	if(!fp(s,p)){puts("0\n0");return 0;}
	res=((1<<31)-1);
	fore(i,0,p.size()){
		int j=p[i];
		int x=e[j].u,y=e[j].v;
		g[x].erase(find(g[x].begin(),g[x].end(),j));
		g[y].erase(find(g[y].begin(),g[y].end(),j));
		p2.clear();
		memset(vis,false,sizeof(vis));
		if(!fp(s,p2)){
			if(c[j]<res){
				res=c[j];
				sol=mp(j,-1);
			}
		}
		else {
			bridges();
			fore(i,0,p2.size()){
				int k=p2[i];
				if(e[k].bridge){
					if(c[j]+c[k]<res){
						res=c[j]+c[k];
						sol=mp(j,k);
					}
				}
			}
		}
		g[x].pb(j);g[y].pb(j);
	}
	if(res==((1<<31)-1))puts("-1");
	else {
		printf("%d\n",res);
		if(sol.snd==-1)printf("1\n%d\n",sol.fst+1);
		else printf("2\n%d %d\n",sol.fst+1,sol.snd+1);
	}
	return 0;
}