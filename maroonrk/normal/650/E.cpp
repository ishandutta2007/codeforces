#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
	
typedef long long ll;
typedef pair<int,int> pii;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

const int Nmax=500000;

struct Edge{
	int x,y,t;
	bool operator<(const Edge& rhs)const{
		return x!=rhs.x?x<rhs.x:y<rhs.y;
	}
} edges[Nmax*2];

struct UnionFind{
	int par[Nmax],rank[Nmax];
	void Init(int n){
		fill(par,par+n,-1);
		fill(rank,rank+n,0);
	}
	int Find(int a){
		return par[a]==-1?a:(par[a]=Find(par[a]));
	}
	void Unite(int a,int b){
		a=Find(a);
		b=Find(b);
		if(a==b)
			return;
		if(rank[a]<rank[b])
			par[a]=b;
		else{
			par[b]=a;
			if(rank[a]==rank[b])
				rank[a]++;
		}
	}
} uf;

vector<pii> tree[2][Nmax];
int	eIdx[Nmax];

void dfs1(int v,int p,int e){
	eIdx[v]=e;
	for(auto c:tree[1][v])
		if(c.first!=p)
			dfs1(c.first,v,c.second);
}

void dfs0(int v,int p,int e){
	for(auto c:tree[0][v])
		if(c.first!=p)
			dfs0(c.first,v,c.second);
	if(p!=-1){
		int f=eIdx[v];
		printf("%d %d %d %d\n",edges[e].x+1,edges[e].y+1,edges[f].x+1,edges[f].y+1);
	}
}

int main(){
	int n=read();
	REP(i,n-1){
		int x=read()-1,y=read()-1;
		if(x>y)
			swap(x,y);
		edges[i]=Edge{x,y,0};
	}
	REP(i,n-1){
		int x=read()-1,y=read()-1;
		if(x>y)
			swap(x,y);
		edges[n-1+i]=Edge{x,y,1};
	}
	sort(edges,edges+(n-1)*2);
	uf.Init(n);
	Edge last=Edge{-1,-1};
	int k=n-1;
	REP(i,(n-1)*2){
		if(last.x==edges[i].x&&last.y==edges[i].y){
			uf.Unite(edges[i].x,edges[i].y);
			k--;
		}
		last=edges[i];
	}
	REP(i,(n-1)*2){
		int x=uf.Find(edges[i].x);
		int y=uf.Find(edges[i].y);
		if(x!=y){
			tree[edges[i].t][x].PB(MP(y,i));
			tree[edges[i].t][y].PB(MP(x,i));
		}
	}
	dfs1(uf.Find(0),-1,-1);
	printf("%d\n",k);
	dfs0(uf.Find(0),-1,-1);
}