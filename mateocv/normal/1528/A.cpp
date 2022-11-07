#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=100005;

vector<ll> g[MAXN];

ll l[MAXN][2];

ll vis[MAXN],pa[MAXN];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			pa[i]=v;
			dfs(i);
		}
	}
}

ll dp[MAXN][2];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	res=0;
	for(auto i:g[x]){
		if(i!=pa[x]){
			res+=max(abs(l[x][y]-l[i][0])+f(i,0),abs(l[x][y]-l[i][1])+f(i,1));
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>l[i][0]>>l[i][1];
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll x,y; cin>>x>>y; x--; y--;
			g[x].pb(y);
			g[y].pb(x);
		}
		fore(i,0,n)pa[i]=-1,vis[i]=0;
		dfs(0);
		fore(i,0,n+1){
			fore(k,0,2){
				dp[i][k]=-1;
			}
		}
		cout<<max(f(0,0),f(0,1))<<"\n";
	}
	
	return 0;
}