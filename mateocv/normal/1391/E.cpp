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

const int MAXN=500005;

vector<ll> g[MAXN];

ll vis[MAXN],d[MAXN],pa[MAXN];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			d[i]=d[v]+1;
			pa[i]=v;
			dfs(i);
		}
	}
}

vector<ll> qd[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		//cout<<"HOLA"<<endl;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		//cout<<"HOLA"<<endl;
		dfs(0);
		//cout<<"HOLA"<<endl;
		ll br=0;
		fore(i,0,n){
			if(d[i]+1>=(n+1)/2){
				vector<ll> res;
				ll pos=i;
				res.pb(i);
				while(pos!=0){
					pos=pa[pos];
					res.pb(pos);
				}
				//assert(SZ(res)>=(n+1)/2);
				cout<<"PATH\n"<<SZ(res)<<"\n";
				for(auto i:res)cout<<i+1<<" "; cout<<"\n";
				br++; break;
			}
		}
		//cout<<"HOLA"<<endl;
		if(br){
			fore(i,0,n)g[i].clear(),qd[i].clear();
			fore(i,0,n)vis[i]=0,d[i]=0,pa[i]=0;
			continue;
		}
		fore(i,0,n)qd[d[i]].pb(i);
		vector<pair<ll,ll>> res;
		fore(i,0,n){
			fore(j,0,SZ(qd[i])){
				if(j&1)continue;
				if(j+1<SZ(qd[i])){
					res.pb({qd[i][j],qd[i][j+1]});
				}
			}
		}
		//assert(2*SZ(res)>=(n+1)/2);
		cout<<"PAIRING\n"<<SZ(res)<<"\n";
		for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
		fore(i,0,n)g[i].clear(),qd[i].clear();
		fore(i,0,n)vis[i]=0,d[i]=0,pa[i]=0;
	}
	return 0;
}