#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

void perdi(){puts("impossible");exit(0);}

int n,m,k;
vector<int> g[300005];
vector<int> g2[300005];
bool vis[300005];
multiset<int> w;

vector<int> c;

void dfs(int x){
	c.pb(x);
	vector<int> p;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(!vis[y])w.erase(w.find(y)),p.pb(y);
	}
	for(multiset<int>::iterator it=w.begin();it!=w.end();++it){
		if(!vis[*it])vis[*it]=true,g2[x].pb(*it);
	}
	fore(i,0,p.size()){
		int y=p[i];
		w.insert(y);
	}
	fore(i,0,g2[x].size()){
		int y=g2[x][i];
		w.erase(w.find(y));
	}
	fore(i,0,g2[x].size()){
		int y=g2[x][i];
		dfs(y);
	}
}

vector<vector<int> > ncomp(){
	fore(i,0,n)g2[i].clear();
	w.clear();
	memset(vis,false,sizeof(vis));
	fore(i,0,n)w.insert(i);
	vector<vector<int> > r;
	fore(i,0,n)if(!vis[i]){
		c.clear();
		vis[i]=true;
		dfs(i);
		r.pb(c);
	}
	return r;
}

bool s0[300005],c0[300005];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	if(n==2){
		if(m)perdi();
	}
	else {
		vector<vector<int> > c=ncomp();
		if(c.size()>1)perdi();
		if(n-1-g[0].size()<k)perdi();
		g[0].clear();
		int q=0;
		fore(i,1,n){
			g[0].pb(i);
			sort(g[i].begin(),g[i].end());
			reverse(g[i].begin(),g[i].end());
			if(!g[i].size()||g[i].back()){
				c0[i]=true;
				s0[i]=g[i].size()==n-2;
				g[i].pb(0);
			}
			reverse(g[i].begin(),g[i].end());
		}
		c=ncomp();
		if(c.size()>k+1)perdi();
		fore(_,0,c.size()){
			if(!c[_][0])continue;
			int qs=0,qc=0;
			fore(i,0,c[_].size()){
				int x=c[_][i];
				qs+=s0[x];
				qc+=c0[x];
			}
			if(!qc||qs>1)perdi();
		}
	}
	puts("possible");
	return 0;
}