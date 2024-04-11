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

const int MAXN=100005,MOD=1000000007;

vector<ll> g[MAXN];
ll vis[MAXN],cant[MAXN];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			dfs(i);
			cant[v]+=cant[i];	
		}
	}
	cant[v]++;
}

ll p[MAXN],val[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(0);
		ll m; cin>>m;
		fore(i,0,m)cin>>p[i];
		sort(p,p+m);
		fore(i,1,n){
			val[i-1]=cant[i]*(n-cant[i]);
		}
		//fore(i,0,n)cout<<cant[i]<<" "; cout<<"\n";
		sort(val,val+n-1);
		//fore(i,0,n-1)cout<<val[i]<<" "; cout<<"\n";
		if(m<n-1){
			reverse(p,p+m);
			reverse(val,val+n-1);
			ll res=0;
			fore(i,0,m)res=(res+p[i]*val[i])%MOD;
			fore(i,m,n-1)res=(res+val[i])%MOD;
			cout<<res<<"\n";
		}else{
			vector<ll> pp;
			fore(i,0,m)pp.pb(p[i]);
			while(SZ(pp)>n-1){
				ll b=pp.back();
				pp.pop_back();
				assert(SZ(pp));
				pp[SZ(pp)-1]=(pp[SZ(pp)-1]*b)%MOD;
			}
			ll res=0;
			fore(i,0,n-1)res=(res+pp[i]*val[i])%MOD;
			cout<<res<<"\n";
		}
		fore(i,0,n)g[i].clear();
		fore(i,0,n)vis[i]=0,cant[i]=0;
		fore(i,0,n-1)val[i]=0;
		fore(i,0,m)p[i]=0;
	}
	
	return 0;
}