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

vector<ll> g[MAXN];

ll vis[MAXN],d[MAXN];

void bfs(ll x) {
	queue<ll>q;
	vis[x]=1;
	q.push(x);
	while(q.size()) {
		auto t=q.front(); q.pop();
		for(auto i:g[t]) {
			if(!vis[i]) {
				vis[i]=1;
				q.push(i);
				d[i]=d[t]+1;
			}
		}
	}
}

const ll MOD=1000000007;

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n)g[i].clear();
		ll a,b; cin>>a>>b; a--; b--;
		fore(i,0,m){
			ll x,y; cin>>x>>y; x--; y--;
			g[x].pb(y);
			g[y].pb(x);
		}
		
		fore(i,0,n)vis[i]=0,d[i]=0;
		bfs(a);
		vector<ll> da(n);
		fore(i,0,n)da[i]=d[i];
		vector<ll> ca(n);
		vector<pair<ll,ll>> va;
		fore(i,0,n)va.pb({da[i],i});
		sort(ALL(va));
		ca[va[0].snd]=1;
		fore(i,1,n){
			ll x=va[i].snd;
			for(auto j:g[x]){
				if(da[j]+1==da[x])ca[x]=(ca[x]+ca[j])%MOD;
			}
		}
		//fore(i,0,n)cout<<da[i]<<" "; cout<<"\n";
		//fore(i,0,n)cout<<ca[i]<<" "; cout<<"\n";
		vector<ll> cca(n);
		cca[va[0].snd]=0;
		fore(i,1,n){
			ll x=va[i].snd;
			for(auto j:g[x]){
				if(da[j]+1==da[x])cca[x]=(cca[x]+cca[j])%MOD;
			}
			for(auto j:g[x]){
				if(da[j]==da[x])cca[x]=(cca[x]+ca[j])%MOD;
			}		
		}
		cout<<(ca[b]+cca[b])%MOD<<"\n";
	}
	
	return 0;
}