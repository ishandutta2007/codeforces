#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define K 17
using namespace std;

typedef long long ll;

vector<pair<int,int> > g[1<<K];
int f[K][1<<K];
int w[K][1<<K];
int e[1<<K];
int d[1<<K];
int res[1<<K];
int n;

void dfs(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i].fst;
		if(y==f[0][x])continue;
		f[0][y]=x;
		e[y]=g[x][i].snd;
		d[y]=d[x]+1;
		dfs(y);
	}
}

void doit(int x, int y){
	if(d[x]<d[y])swap(x,y);
	for(int k=K-1;k>=0;--k){
		if(d[x]-(1<<k)>=d[y])w[k][x]++,x=f[k][x];
	}
	assert(d[x]==d[y]);
	if(x==y)return;
	for(int k=K-1;k>=0;--k){
		if(f[k][x]!=f[k][y]){
			w[k][x]++;x=f[k][x];
			w[k][y]++;y=f[k][y];
		}
	}
	assert(x!=y&&f[0][x]==f[0][y]);
	w[0][x]++;
	w[0][y]++;
}

int main(){
	scanf("%d",&n);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(mp(y,i));
		g[y].pb(mp(x,i));
	}
	e[0]=f[0][0]=-1;
	dfs(0);
	fore(k,1,K){
		fore(i,0,n){
			if(f[k-1][i]>=0)f[k][i]=f[k-1][f[k-1][i]];
			else f[k][i]=-1;
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		doit(x,y);
	}
	for(int k=K-1;k>0;--k){
		fore(i,0,n){
			w[k-1][i]+=w[k][i];
			if(f[k-1][i]>=0)w[k-1][f[k-1][i]]+=w[k][i];
		}
	}
	fore(i,1,n)res[e[i]]=w[0][i];
	fore(i,1,n){
		if(i>1)putchar(' ');
		printf("%d",res[i]);
	}
	puts("");
	return 0;
}