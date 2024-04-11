#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
#define S 320
using namespace std;
typedef long long ll;

map<pair<int,int>,int> c;
int n,m;
vector<pair<int,int> > w[100005];
vector<int> g[100005];
int uf[S+5][100005];
bool vis[100005];
vector<int> z;

void dfs(int x, vector<int>& t){
	if(vis[x])return;
	vis[x]=1;t.pb(x);
	for(int y:g[x])dfs(y,t);
}

int find(int k, int x){
	if(uf[k][x]<0)return x;
	return uf[k][x]=find(k,uf[k][x]);
}

void join(int k, int x, int y){
	x=find(k,x);y=find(k,y);
	if(x==y)return;
	if(uf[k][x]>uf[k][y])swap(x,y);
	uf[k][x]+=uf[k][y];uf[k][y]=x;
}

int main(){
	mset(uf,-1);
	scanf("%d%d",&n,&m);
	fore(_,0,m){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);x--;y--;c--;
		w[c].pb(mp(x,y));
	}
	fore(i,0,m){
		if(!SZ(w[i]))continue;
		if(SZ(w[i])<S){
			for(auto p:w[i])g[p.fst].pb(p.snd),g[p.snd].pb(p.fst);
			for(auto p:w[i])if(!vis[p.fst]){
				vector<int> t;
				dfs(p.fst,t);
				sort(t.begin(),t.end());
				fore(i,0,SZ(t))fore(j,i+1,SZ(t))c[mp(t[i],t[j])]++;
			}
			for(auto p:w[i]){
				g[p.fst].clear();vis[p.fst]=0;
				g[p.snd].clear();vis[p.snd]=0;
			}
		}
		else {
			z.pb(i);
			for(auto p:w[i])join(i,p.fst,p.snd);
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		if(x>y)swap(x,y);
		int r=c[mp(x,y)];
		for(int t:z)r+=find(t,x)==find(t,y);
		printf("%d\n",r);
	}
	return 0;
}