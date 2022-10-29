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
using namespace std;
typedef long long ll;

int n,m;
int c[100005];
int w[100005];
int t[100005];
int rr[100005];
int s[100005];
vector<pair<int,int> > q[100005];

vector<int> g[100005];

void add(int a){
	w[a]++;
	t[w[a]]++;
}

void del(int a){
	t[w[a]]--;
	w[a]--;
}

void dfs0(int x, int f){
	s[x]=1;
	for(int y:g[x])if(y!=f){
		dfs0(y,x);
		s[x]+=s[y];
	}
}

void dfs2(int x, int f){
	add(c[x]);
	for(int y:g[x])if(y!=f)dfs2(y,x);
}

void dfs3(int x, int f){
	del(c[x]);
	for(int y:g[x])if(y!=f)dfs3(y,x);
}

void dfs1(int x, int f, bool b){
	int z=-1;
	for(int y:g[x])if(y!=f&&(z<0||s[y]>s[z]))z=y;
	for(int y:g[x])if(y!=f&&y!=z)dfs1(y,x,false);
	if(z>=0)dfs1(z,x,true);
	add(c[x]);
	for(int y:g[x])if(y!=z&&y!=f)dfs2(y,x);
	for(auto p:q[x])rr[p.snd]=t[p.fst];
	if(!b)dfs3(x,f);
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%d",c+i),c[i]--;
	fore(_,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	fore(i,0,m){
		int x,k;
		scanf("%d%d",&x,&k);x--;
		q[x].pb(mp(k,i));
	}
	dfs0(0,-1);
	dfs1(0,-1,false);
	fore(i,0,m)printf("%d\n",rr[i]);
	return 0;
}