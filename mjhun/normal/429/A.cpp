#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n;
vector<int> g[100005];
int d[100005];
int v[100005];
int w[2];
vector<int> sol;

void dfs(int x, int f){
	bool c=false;
	if(v[x]^w[d[x]]){
		c=true;
		sol.pb(x);
		w[d[x]]^=1;
	}
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f)continue;
		d[y]=1-d[x];
		dfs(y,x);
	}
	if(c)w[d[x]]^=1;
}

int main(){
	scanf("%d",&n);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	fore(i,0,n){
		scanf("%d",v+i);
	}
	fore(i,0,n){
		int a;
		scanf("%d",&a);
		v[i]^=a;
	}
	dfs(0,-1);
	printf("%d\n",(int)sol.size());
	fore(i,0,sol.size())printf("%d\n",sol[i]+1);
	return 0;
}