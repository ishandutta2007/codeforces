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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

#define MAXN 200005

vector<pair<int,pair<int,int> > > r;
vector<int> g2[MAXN];

ll dfs2(int x, int d){
	ll r=1LL*d*d;
	for(int y:g2[x])r+=dfs2(y,d+1);
	return r;
}

vector<int> g[MAXN];int n;
bool tk[MAXN];
int fat[MAXN]; // father in centroid decomposition
int szt[MAXN]; // size of subtree
int calcsz(int x, int f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
bool dfss(int x, int f, int q){
	for(int y:g[x]){
		if(y==q)return true;
		if(!tk[y]&&y!=f&&dfss(y,x,q))return true;
	}
	return false;
}
int ff[MAXN];
bool dfs3(int x, int f, vector<int>& v){
	v.pb(x);ff[x]=f;
	for(int y:g[x])if(y!=f)dfs3(y,x,v);
}
void cdfs(int x=0, int f=-1, int sz=-1){ // O(nlogn)
	if(sz<0)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	int z=-1;
	sz=calcsz(x,-1);
	for(int y:g[x])if(!tk[y]&&szt[y]*2>=sz){z=y;break;}
	tk[x]=true;fat[x]=f;
	if(z>=0)tk[z]=true,fat[z]=f;
	for(int y:g[x])if(!tk[y]){
		vector<int> v;
		dfs3(y,x,v);
		int p=y;
		for(int a:v)if(a!=y){
			r.pb(mp(x,mp(p,a)));
			if(ff[a]!=y)r.pb(mp(a,mp(ff[a],y)));
			p=a;
		}
		if(p!=y)r.pb(mp(x,mp(p,y)));
	}
	if(z>=0){
		for(int y:g[z])if(!tk[y]){
			vector<int> v;
			dfs3(y,z,v);
			int p=y;
			for(int a:v)if(a!=y){
				r.pb(mp(z,mp(p,a)));
				if(ff[a]!=y)r.pb(mp(a,mp(ff[a],y)));
				p=a;
			}
			if(p!=y)r.pb(mp(z,mp(p,y)));
			//printf("  %d %d %d\n",r.back().fst+1,r.back().snd.fst+1,r.back().snd.snd+1);
		}
	}
}
void centroid(){memset(tk,false,sizeof(tk));cdfs();}

int main(){
	while(scanf("%d",&n)!=EOF){
		fore(i,1,n){
			int x,y;
			scanf("%d%d",&x,&y);x--;y--;
			g[x].pb(y);
			g[y].pb(x);
		}
		centroid();
		//reverse(r.begin(),r.end());
		printf("%d\n",SZ(r));
		for(auto p:r)printf("%d %d %d\n",p.fst+1,p.snd.fst+1,p.snd.snd+1);
		r.clear();
		fore(i,0,n)g[i].clear(),g2[i].clear();
		puts("");
	}
	return 0;
}
//