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

vector<pair<ll,ll>> g[MAXN];

ll vis[MAXN],cant[MAXN],par[MAXN];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(vis[i.fst])continue;
		dfs(i.fst);
		cant[v]+=cant[i.fst];
		par[i.fst]=i.snd;
	}
	if(SZ(g[v])==1)cant[v]=1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,s; cin>>n>>s;
		pair<ll,ll> w[n];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v>>w[i].fst>>w[i].snd; u--; v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		ll res=1e18,val=0;
		dfs(0);
		//fore(i,0,n)cout<<cant[i]<<" "; cout<<endl;
		vector<ll> v[2];
		fore(i,1,n){
			val+=cant[i]*w[par[i]].fst;
			while(w[par[i]].fst){
				v[w[par[i]].snd-1].pb(cant[i]*((w[par[i]].fst+1)/2));
				w[par[i]].fst/=2;
			}
		}
		fore(k,0,2)sort(ALL(v[k]));
		//fore(k,0,2)reverse(ALL(v[k]));
		/*fore(k,0,2){
			for(auto i:v[k])cout<<i<<" "; cout<<"\n";
		}*/
		ll r=SZ(v[1])-1;
		fore(i,0,SZ(v[0]))val-=v[0][i];
		fore(i,0,SZ(v[0])+1){
			while(r>=0&&val>s)val-=v[1][r],r--;
			if(val<=s)res=min(res,SZ(v[0])-i+2*(SZ(v[1])-r-1));
			if(i==SZ(v[0]))break;
			val+=v[0][i];
			//cout<<i<<" "<<r<<"\n";
		}

		cout<<res<<"\n";
		fore(i,0,n)g[i].clear();
		fore(i,0,n)vis[i]=0,cant[i]=0,par[i]=0;
	}
	
	return 0;
}