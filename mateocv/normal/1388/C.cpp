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

vector<ll> g[100005];

ll p[100005],vis[100005],s[100005],pa[100005];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			dfs(i);
			pa[i]=v;
			s[v]+=s[i];
		}
	}
	s[v]+=p[v];
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n)cin>>p[i];
		ll h[n];
		fore(i,0,n)cin>>h[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		fore(i,0,n)vis[i]=0;
		fore(i,0,n)s[i]=0;
		fore(i,0,n)pa[i]=-1;
		dfs(0);
		//fore(i,0,n)cout<<s[i]<<" "; cout<<"\n";
		ll d[n];
		fore(i,0,n)d[i]=(s[i]-h[i])/2;
		//fore(i,0,n)cout<<d[i]<<" "; cout<<"\n";
		ll br=0;
		fore(i,0,n){
			ll sum=0;
			for(auto j:g[i]){
				if(j!=pa[i]){
					sum+=d[j];
				}
			}
			if(((s[i]-h[i])&1)||d[i]<0||sum<d[i]-p[i]||d[i]>s[i]){
				//cout<<"fue "<<i<<"\n";
				br++; break;
			}
		}
		if(br){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}
		fore(i,0,n)g[i].clear();
	}
	
	return 0;
}