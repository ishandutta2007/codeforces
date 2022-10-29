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
#define MOD 1000000007
using namespace std;
typedef long long ll;

pair<int,int> add(pair<int,int> a, pair<int,int> b){return mp(a.fst+b.fst,a.snd+b.snd);}

int p2[200005],p3[200005];
set<int> g[200005];int n,m;
int f[200005];
vector<vector<int> > c;int ci[200005];
pair<int,int> v[200005];

void dfs(int x){
	for(int y:g[x]){
		if(y==f[x])continue;
		if(f[y]==-1)f[y]=x,dfs(y);
		else if(ci[y]<0){
			vector<int> v={y};
			for(int z=x;z!=y;z=f[z])v.pb(z);
			for(int z:v)ci[z]=SZ(c);
			c.pb(v);
		}
	}
}

int p[18][200005],d[200005];
pair<int,int> w[18][200005];

void dfs1(int x){
	for(int y:g[x]){
		if(y==p[0][x])continue;
		d[y]=d[x]+1;p[0][y]=x;
		dfs1(y);
	}
}

int main(){
	p2[0]=p3[0]=1;
	fore(i,1,100005)p2[i]=2LL*p2[i-1]%MOD,p3[i]=3LL*p3[i-1]%MOD;
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].insert(y);g[y].insert(x);
	}
	memset(f,-1,sizeof(f));memset(ci,-1,sizeof(ci));
	f[0]=-2;dfs(0);
	fore(i,0,n)if(ci[i]>=0)v[i]=mp(1,0);
	fore(i,0,SZ(c)){
		v[n]=mp(0,1);
		fore(j,0,SZ(c[i])){
			int x=c[i][j],y=c[i][(j+1)%SZ(c[i])];
			g[x].erase(y);g[y].erase(x);
			g[n].insert(x);g[x].insert(n);
		}
		n++;
	}
	fore(i,0,n)w[0][i]=v[i];
	p[0][0]=-1;dfs1(0);
	fore(k,1,18)fore(i,0,n){
		if(p[k-1][i]<0){
			p[k][i]=-1;
			w[k][i]=w[k-1][i];
		}
		else {
			p[k][i]=p[k-1][p[k-1][i]];
			w[k][i]=add(w[k-1][i],w[k-1][p[k-1][i]]);
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		if(d[x]<d[y])swap(x,y);
		pair<int,int> r=mp(0,0);
		for(int k=17;k>=0;--k)if(d[x]-(1<<k)>=d[y]){
			r=add(r,w[k][x]);
			x=p[k][x];
		}
		assert(d[x]==d[y]);
		if(x!=y){
			for(int k=17;k>=0;--k)if(p[k][x]!=p[k][y]){
				r=add(r,w[k][x]);r=add(r,w[k][y]);
				x=p[k][x];y=p[k][y];
			}
			assert(x!=y&&p[0][x]==p[0][y]);
			r=add(r,v[x]);r=add(r,v[y]);r=add(r,v[p[0][x]]);
		}
		else r=add(r,v[x]);
		printf("%lld\n",1LL*p2[r.snd]*p2[r.fst-2*r.snd]%MOD);
	}
	return 0;
}