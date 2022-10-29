#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

vector<int> g[1<<20];
bool vis[1<<20];
bool h[1<<20];
int n,m;

void dfs(int x){
	if(vis[x])return;
	vis[x]=true;
	for(int y:g[x])dfs(y);
}

int main(){
	int l=0;
	scanf("%d%d",&n,&m);
	fore(i,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		h[x]=true;h[y]=true;
		if(x!=y)g[x].pb(y),g[y].pb(x);
		else l++;
	}
	fore(i,0,n)if(h[i]){dfs(i);break;}
	fore(i,0,n)if(h[i]&&!vis[i]){puts("0");return 0;}
	ll r=0;
	fore(i,0,n){
		int q=g[i].size();
		r+=(1LL*q*(q-1))/2;
	}
	r+=(1LL*l*(l-1))/2;
	r+=1LL*l*(m-l);
	printf("%lld\n",r);
	return 0;
}