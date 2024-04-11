#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define INF (1LL<<61)
using namespace std;

typedef long long ll;

ll dp[5005][5005];
vector<pair<int,int> > g[5005];
int n,m;

ll f(int x, int q){
	if(dp[x][q]>=0)return dp[x][q];
	ll r;
	if(q==0)r=INF;
	else if(q==1){
		r=x==n-1?0:INF;
	}
	else {
		r=INF;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst;
			int c=g[x][i].snd;
			r=min(r,c+f(y,q-1));
		}
	}
	return dp[x][q]=r;
}

vector<int> sol;

void gen(int x, int q){
	sol.pb(x);
	if(q==1)return;
	fore(i,0,g[x].size()){
		int y=g[x][i].fst;
		int c=g[x][i].snd;
		if(c+f(y,q-1)==dp[x][q]){
			gen(y,q-1);
			return;
		}
	}
}

int main(){
	int t;
	scanf("%d%d%d",&n,&m,&t);
	while(m--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);a--;b--;
		g[a].pb(mp(b,c));
	}
	memset(dp,-1,sizeof(dp));
	int r;
	for(int i=2;i<=n;++i)if(f(0,i)<=t)r=i;
	gen(0,r);
	assert(sol.size()==r);
	printf("%d\n%d",r,sol[0]+1);
	fore(i,1,sol.size())printf(" %d",sol[i]+1);puts("");
	return 0;
}