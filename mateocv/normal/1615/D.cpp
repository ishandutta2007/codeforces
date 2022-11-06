#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=200005;

vector<ll> g[MAXN];

ll vis[MAXN],p[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto i:g[x]){
		if(!vis[i]){
			p[i]=x;
			dfs(i);
		}
	}
}

int pa[MAXN],sz[MAXN];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x;
		else sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}

vector<ll> g2[MAXN];

ll vis2[MAXN],co[MAXN];

void dfs2(ll x){
	vis2[x]=1;
	for(auto i:g2[x]){
		if(!vis2[i]){
			co[i]=co[x]^1;
			dfs2(i);
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n)g[i].clear();
		map<pair<ll,ll>,ll> mp;
		fore(i,0,n-1){
			ll x,y,w; cin>>x>>y>>w; x--; y--;
			g[x].pb(y);
			g[y].pb(x);
			if(w!=-1)mp[{min(x,y),max(x,y)}]=w;
		}
		fore(i,0,n)vis[i]=0,p[i]=0;
		dfs(0);
		vector<pair<ll,ll>> vr[2];
		fore(i,0,m){
			ll x,y,p; cin>>x>>y>>p; x--; y--;
			vr[p].pb({x,y});
		}
		dsu_init(n);
		for(auto i:vr[0]){
			join(i.fst,i.snd);
		}
		for(auto i:mp){
			if(__builtin_popcount(i.snd)%2==0){
				join(i.fst.fst,i.fst.snd);
			}
		}
		fore(i,0,n)g2[i].clear();
		ll br=0;
		for(auto i:vr[1]){
			if(find_pa(i.fst)==find_pa(i.snd))br++;
			g2[find_pa(i.fst)].pb(find_pa(i.snd));
			g2[find_pa(i.snd)].pb(find_pa(i.fst));
		}
		for(auto i:mp){
			if(__builtin_popcount(i.snd)%2==1){
				ll x=find_pa(i.fst.fst),y=find_pa(i.fst.snd);
				if(x==y)br++;
				g2[x].pb(y);
				g2[y].pb(x);
			}
		}
		if(br){
			cout<<"NO\n";
			continue;
		}
		fore(i,0,n)vis2[i]=0,co[i]=0;
		fore(i,0,n){
			if(!vis2[i])dfs2(i);
		}
		fore(i,0,n){
			for(auto j:g2[i]){
				if(co[i]==co[j])br++;
			}
		}
		if(br){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		fore(i,1,n){
			pair<ll,ll> pp={min(i,p[i]),max(i,p[i])};
			if(mp[pp]){
				cout<<i+1<<" "<<p[i]+1<<" "<<mp[pp]<<"\n";
			}else{
				cout<<i+1<<" "<<p[i]+1<<" "<<(co[find_pa(i)]^co[find_pa(p[i])])<<"\n";
			}
		}
	}	
	
	return 0;
}