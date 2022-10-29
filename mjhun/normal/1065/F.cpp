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

int f[20][1<<20];
int q[1<<20],d[1<<20],w[1<<20];pair<int,int> z[1<<20];
vector<int> g[1<<20];
int n,k,r;

void dfs0(int x){
	z[x]=mp(n+2,0);
	for(int y:g[x]){
		d[y]=d[x]+1;dfs0(y);
		z[x]=min(z[x],z[y]);
	}
	if(!SZ(g[x]))z[x]=mp(d[x],x);
}

int dfs(int x){
	int r=0;
	for(int y:g[x])r=max(r,dfs(y));
	r+=q[x];
	return r;
}

pair<int,int> xx[1<<20];

int main(){
	scanf("%d%d",&n,&k);
	f[0][0]=-1;
	fore(i,1,n)scanf("%d",&f[0][i]),f[0][i]--,g[f[0][i]].pb(i);
	dfs0(0);
	fore(k,1,20)fore(i,0,n){
		if(f[k-1][i]<0)f[k][i]=-1;
		else f[k][i]=f[k-1][f[k-1][i]];
	}
	fore(i,0,n)xx[i]=mp(d[i],i);
	sort(xx,xx+n);
	fore(_,0,n){
		int x=xx[_].snd,y=xx[_].snd;
		if(SZ(g[x]))continue;
		fore(i,0,20)if(k&(1<<i)){
			x=f[i][x];
			if(x<0)break;
		}
		w[y]=x;
		if(x>=0&&z[x].fst<d[y])w[y]=w[z[x].snd];
	}
	fore(i,0,n)if(!SZ(g[i])){
		if(w[i]<0)r++;
		else q[w[i]]++;
	}
	r+=dfs(0);
	printf("%d\n",r);
	return 0;
}