#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

vector<int> g[200005];
int d[200005];
int w[200005];
int f[200005];
int n,k;

void dfs(int x){
	w[x]=d[x];
	for(int y:g[x]){
		if(y==f[x])continue;
		f[y]=x;
		d[y]=d[x]+1;
		dfs(y);
		w[x]=max(w[x],w[y]);
	}
}

int main(){
	scanf("%d%d",&n,&k);k--;
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	f[0]=-1;
	dfs(0);
	int x=k;
	while(d[x]-1>d[k]-d[x]+1)x=f[x];
	printf("%d\n",2*w[x]);
	return 0;
}