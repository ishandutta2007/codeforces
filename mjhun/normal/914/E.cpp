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

char s[MAXN];
vector<int> g[MAXN];int n;
bool tk[MAXN];
int fat[MAXN];
int szt[MAXN];
int c[1<<20];
ll r[MAXN],z[MAXN];
int calcsz(int x, int f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
void dfs(int x, int f, int c, vector<pair<int,int> >& v){
	c^=1<<s[x];
	v.pb(mp(x,c));
	for(int y:g[x])if(!tk[y]&&y!=f)dfs(y,x,c,v);
}
void dfs2(int x, int f){
	for(int y:g[x])if(!tk[y]&&y!=f){
		dfs2(y,x);
		z[x]+=z[y];
	}
	r[x]+=z[x];
}
void cdfs(int x=0, int f=-1, int sz=-1){
	if(sz<0)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	tk[x]=true;fat[x]=f;r[x]++;

	vector<vector<pair<int,int> > > w;

	for(int y:g[x])if(!tk[y]){
		vector<pair<int,int> > v;
		dfs(y,x,0,v);
		w.pb(v);
		for(auto p:v)c[p.snd]++;
	}
	ll asd=0;
	for(auto v:w){
		for(auto p:v)c[p.snd]--;
		for(auto p:v){
			fore(i,0,20){
				z[p.fst]+=c[(1<<i)^(1<<s[x])^p.snd];
				asd+=c[(1<<i)^(1<<s[x])^p.snd];
			}
			z[p.fst]+=c[(1<<s[x])^p.snd];
			asd+=c[(1<<s[x])^p.snd];
			if(__builtin_popcount(p.snd^(1<<s[x]))<=1){
				r[x]++;
				z[p.fst]++;
			}
		}
		for(auto p:v)c[p.snd]++;
	}
	assert(asd%2==0);
	r[x]+=asd/2;
	for(int y:g[x])if(!tk[y]){
		dfs2(y,x);
	}
	for(auto v:w)for(auto p:v)c[p.snd]--,z[p.fst]=0;
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){memset(tk,false,sizeof(tk));cdfs();}

int main(){
	scanf("%d",&n);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	scanf("%s",s);
	fore(i,0,n)s[i]-='a';
	centroid();
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%lld",r[i]);
	}
	puts("");
	return 0;
}