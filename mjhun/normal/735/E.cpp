#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;
typedef long long ll;

vector<int> g[128];
int n,k;
int f[128][32][32]; // nodo, min dist de root a negro, max dist de root a malo
int f2[128][32][32];

void dfs(int x, int p){
	f[x][k+1][0]=1;
	fore(_,0,g[x].size()){
		int y=g[x][_];
		if(y==p)continue;
		dfs(y,x);
		memset(f2[x],0,sizeof(f2[x]));
		fore(d0,1,k+2)fore(d1,0,k+1)fore(d00,0,k+2)fore(d11,0,k){
			int w0=min(d0,d00+1);
			int w1=max(d1,d11+1);
			if(!d11&&d00<=k)w1=d1;
			if(w1+w0<=k)w1=0;
			f2[x][w0][w1]+=(1LL*f[x][d0][d1]*f[y][d00][d11])%MOD;
			f2[x][w0][w1]%=MOD;
		}
		memcpy(f[x],f2[x],sizeof(f[x]));
	}
	fore(d0,1,k+2)fore(d1,0,k+1)f[x][0][0]+=f[x][d0][d1],f[x][0][0]%=MOD;
}

int main(){
	scanf("%d%d",&n,&k);
	fore(_,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	if(k==0){puts("1");return 0;}
	dfs(0,-1);
	int r=0;
	fore(i,0,k+1)r+=f[0][i][0],r%=MOD;
	printf("%d\n",r);
	return 0;
}