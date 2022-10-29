#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int uf[1024];

int find(int x){
	if(uf[x]==x)return x;
	return uf[x]=find(uf[x]);
}

void join(int x, int y){
	x=find(x);y=find(y);
	if(x==y)return;
	uf[x]=y;
}

vector<int> g[1024];
int n,m,mw;
int w[1024];
int b[1024];
int dp[1024][1024];

int f(int k, int ww){
	if(dp[k][ww]>=0)return dp[k][ww];
	int x=k-1,sb=0,sw=0;
	int r=f(k-1,ww);
	fore(_,0,g[x].size()){
		int i=g[x][_];
		sb+=b[i];
		sw+=w[i];
		if(w[i]<=ww)r=max(r,b[i]+f(k-1,ww-w[i]));
	}
	if(sw<=ww)r=max(r,sb+f(k-1,ww-sw));
	return dp[k][ww]=r;
}


int main(){
	fore(i,0,1024)uf[i]=i;
	scanf("%d%d%d",&n,&m,&mw);
	fore(i,0,n)scanf("%d",w+i);
	fore(i,0,n)scanf("%d",b+i);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		join(x,y);
	}
	fore(i,0,n)g[find(i)].pb(i);
	memset(dp,-1,sizeof(dp));
	memset(dp[0],0,sizeof(dp[0]));
	printf("%d\n",f(n,mw));
	return 0;
}