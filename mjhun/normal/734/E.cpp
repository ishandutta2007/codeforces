#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int n;
int nc;
int c[200005];
int w[200005];
vector<int> g[200005];
vector<int> g2[200005];

void dfs0(int x, int k){
	w[x]=k;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(c[y]==c[x]&&w[y]<0)dfs0(y,k);
	}
}

int d[200005];

void dfs1(int x, int f){
	fore(i,0,g2[x].size()){
		int y=g2[x][i];
		if(y==f)continue;
		d[y]=d[x]+1;
		dfs1(y,x);
	}
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",c+i);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	memset(w,-1,sizeof(w));
	fore(i,0,n){
		if(w[i]<0){
			dfs0(i,nc++);
		}
	}
	fore(x,0,n)fore(i,0,g[x].size()){
		int y=g[x][i];
		if(w[x]!=w[y])g2[w[x]].pb(w[y]);
	}
	d[0]=0;
	dfs1(0,-1);
	int k=0;
	fore(i,1,nc){
		if(d[i]>d[k])k=i;
	}
	d[k]=0;
	dfs1(k,-1);
	int r=0;
	fore(i,0,nc)r=max(r,d[i]);
	printf("%d\n",(r+1)/2);
	return 0;
}