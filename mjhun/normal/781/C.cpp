#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

vector<int> g[200005];
bool vis[200005];
vector<int> r;
int n,m,k;

void dfs(int x){
	r.pb(x);
	for(auto y:g[x]){
		if(vis[y])continue;
		vis[y]=true;
		dfs(y);
		r.pb(x);
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		g[a].pb(b);g[b].pb(a);
	}
	vis[0]=true;dfs(0);
	m=(2*n+k-1)/k;
	int j=0;
	fore(i,0,k){
		vector<int> z;
		fore(_,0,m){
			if(j==r.size())break;
			z.pb(r[j++]);
		}
		if(z.empty())z.pb(0);
		printf("%d",(int)z.size());
		for(int x:z)printf(" %d",x+1);puts("");
	}
	return 0;
}