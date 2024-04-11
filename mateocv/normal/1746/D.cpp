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

const int MAXN=200005;

ll p[MAXN],s[MAXN],c[MAXN],dp[MAXN][2];

vector<ll> g[MAXN];

void dfs(ll x){
	dp[x][0]=s[x]*c[x];
	dp[x][1]=s[x]*(c[x]+1);
	if(SZ(g[x])==0)return;
	ll su=0;
	vector<ll> d;
	for(auto i:g[x]){
		c[i]=c[x]/SZ(g[x]);
		dfs(i);
		su+=dp[i][0];
		d.pb(dp[i][1]-dp[i][0]);
	}
	sort(ALL(d));
	reverse(ALL(d));
	fore(i,0,c[x]-(c[x]/SZ(g[x]))*SZ(g[x])){
		su+=d[i];
	}
	dp[x][0]+=su;
	dp[x][1]+=su+d[c[x]-(c[x]/SZ(g[x]))*SZ(g[x])];
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		fore(i,0,n)g[i].clear();
		p[0]=-1;
		fore(i,1,n){
			cin>>p[i]; p[i]--;
			g[p[i]].pb(i);
		}
		fore(i,0,n)cin>>s[i];
		c[0]=k;
		dfs(0);
		cout<<dp[0][0]<<"\n";
	}
	
	return 0;
}