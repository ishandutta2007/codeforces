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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

vector<int> g[200005];int n;
int z[200005];

void dfs(int x, int p){
	bool h=false;
	for(int y:g[x])if(y!=p)h=true;
	if(!h){z[x]=1;return;}
	for(int y:g[x])if(y!=p)dfs(y,x),z[x]+=z[y];
}

int f0(int x, int p, int d){
	int s=0;
	for(int y:g[x])if(y!=p)s+=z[y];
	if(!s)return 0;
	if(!d){
		int r=-1;
		for(int y:g[x])if(y!=p)r=max(r,s-z[y]+f0(y,x,d^1));
		return r;
	}
	else {
		int r=0;
		for(int y:g[x])if(y!=p)r+=f0(y,x,d^1);
		return r;
	}
}

int f1(int x, int p, int d){
	int s=0;
	for(int y:g[x])if(y!=p)s+=z[y];
	if(!s)return 0;
	if(d){
		int r=-1;
		for(int y:g[x])if(y!=p)r=max(r,s-z[y]+f1(y,x,d^1));
		return r;
	}
	else {
		int r=0;
		for(int y:g[x])if(y!=p)r+=f1(y,x,d^1);
		return r;
	}
}


int main(){
	scanf("%d",&n);
	fore(_,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	dfs(0,-1);
	printf("%d %d\n",1+f0(0,-1,0),z[0]-f0(0,-1,1));
	return 0;
}