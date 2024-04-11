#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;

vector<int> g[300005];int n;
int f[300005][32]; // para cada d, mejor k
int w[300005];
int a[300005];int m;
ll r;

void dfs(int x, int p){
	w[x]=1;
	for(int y:g[x])if(y!=p){
		dfs(y,x);
		w[x]=max(w[x],1+w[y]);
	}
	f[x][1]=n;
	fore(d,2,21){
		m=0;
		for(int y:g[x])if(y!=p)a[m++]=f[y][d-1];
		sort(a,a+m);reverse(a,a+m);
		f[x][d]=0;
		while(f[x][d]<m&&a[f[x][d]]>f[x][d])f[x][d]++;
		f[x][d]=max(f[x][d],1);
	}
	f[x][21]=1;
}

void dfs2(int x, int p){
	for(int y:g[x])if(y!=p){
		dfs2(y,x);
		fore(d,1,21)f[x][d]=max(f[x][d],f[y][d]);
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
	dfs2(0,-1);
	fore(i,0,n){
		r+=w[i];
		fore(d,1,21)r+=d*(f[i][d]-f[i][d+1]);
	}
	printf("%lld\n",r);
	return 0;
}