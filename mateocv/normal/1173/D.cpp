#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MOD=998244353;
vector<ll> g[200005];
ll vis[200005];

ll fact[200005];

ll f(ll x){
	ll &r=fact[x];
	if(r>=0)return r;
	if(x==0){
		r=1; return r;
	}
	r=(x*f(x-1))%MOD; return r;
}

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

/*void bfs(){
	queue<ll> q;
	q.push(0);
	vis[0]=1;
	while(SZ(q)){
		ll t=q.top(); q.pop();
		for(auto i:g[t]){
			if(!vis[i]){
				q.push(i);
				vis[i]=1;
			}
		}
	}
}*/
//pair<ll,ll> dp[200005];

ll dfs(ll v){
	if(vis[v]){
		//cout<<"En "<<v<<" devuelvo 1 por repe\n";
		return 1;
	}
	vis[v]=1;
	ll res=1;
	for(auto i:g[v]){
		res*=dfs(i);
		res%=MOD;
	}
	res*=f(SZ(g[v]));
	res%=MOD;
	//cout<<"En "<<v<<" devuelvo "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	ll u,v;
	fore(i,0,n-1){
		cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	//mset(dp,-1);
	mset(fact,-1);
	cout<<(dfs(0)*n)%MOD;
	
	return 0;
}