#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,m;
vector<int> g[100005];
int vis[100005];
vector<vector<int> > r;

bool dfs(int x, int f){
	vis[x]=1;
	int k=-1;
	for(int y:g[x]){
		if(y==f)continue;
		if(vis[y]>0||!vis[y]&&!dfs(y,x)){
			if(k<0)k=y;
			else r.pb({k,x,y}),k=-1;
		}
	}
	vis[x]=-1;
	if(k>=0){
		r.pb({k,x,f});
		return true;
	}
	return false;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(_,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	fore(i,0,n)if(!vis[i]&&dfs(i,-1)){puts("No solution");return 0;}
	for(auto v:r)printf("%d %d %d\n",v[0]+1,v[1]+1,v[2]+1);
	return 0;
}