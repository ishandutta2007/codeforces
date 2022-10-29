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

vector<pair<int,int> > g[1<<19];
int s[1<<19],d[1<<19],r[1<<19];
int f[1<<22],w;
int n;

void dfs2(int x, int m, int dd, int& r){
	if(f[m]>=0)r=max(r,f[m]+d[x]-2*dd);
	fore(i,0,22){
		int m2=m^(1<<i);
		if(f[m2]>=0)r=max(r,f[m2]+d[x]-2*dd);
	}
	for(auto p:g[x]){
		int y=p.fst,c=p.snd;
		dfs2(y,m^(1<<c),dd,r);
	}
}

void dfs3(int x, int m){
	f[m]=max(f[m],d[x]);
	for(auto p:g[x]){
		int y=p.fst,c=p.snd;
		dfs3(y,m^(1<<c));
	}
}

void dfs4(int x, int m){
	f[m]=-1;
	for(auto p:g[x]){
		int y=p.fst,c=p.snd;
		dfs4(y,m^(1<<c));
	}
}

void dfs0(int x){
	s[x]=1;
	for(auto p:g[x])d[p.fst]=d[x]+1,dfs0(p.fst),s[x]+=s[p.fst];
}

void dfs1(int x, bool clear=true){
	if(!SZ(g[x])){
		if(!clear)f[w]=max(f[w],d[x]);
		return;
	}
	int z=g[x][0].fst,zc=g[x][0].snd;
	for(auto p:g[x])if(s[p.fst]>s[z])z=p.fst,zc=p.snd;
	for(auto p:g[x])if(p.fst!=z)dfs1(p.fst),r[x]=max(r[x],r[p.fst]);
	dfs1(z,false);r[x]=max(r[x],r[z]);w^=1<<zc;
	r[x]=max(r[x],f[w]-d[x]);
	fore(i,0,22){
		int m=w^(1<<i);
		if(f[m]>=0)r[x]=max(r[x],f[m]-d[x]);
	}
	f[w]=max(f[w],d[x]);
	for(auto p:g[x]){
		int y=p.fst,c=p.snd;
		if(y==z)continue;
		dfs2(y,w^(1<<c),d[x],r[x]);
		dfs3(y,w^(1<<c));
	}
	if(clear)dfs4(x,w);
}

int main(){
	scanf("%d",&n);
	fore(i,1,n){
		int p;char s[4];
		scanf("%d%s",&p,s);p--;
		g[p].pb(mp(i,s[0]-'a'));
	}
	mset(f,-1);
	dfs0(0);dfs1(0);
	fore(i,0,n)printf("%d%c",r[i]," \n"[i==n-1]);
	return 0;
}