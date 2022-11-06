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

ll INF=1e18;

vector<ll> g[2020];
vector<ll> ga[2020];
vector<ll> gb[2020];

ll c[2020];
ll d[2020];
ll vis[2020];
vector<pair<ll,ll>> res;
vector<pair<ll,ll>> inf; 

void dfs(ll o, ll v){
	if(vis[v])return;
	vis[v]=1;
	if(v!=o){
		ga[o].pb(v);
		gb[v].pb(o);	
	}
	for(auto i:g[v])dfs(o,i);
}

void dfs2(ll p,ll v){
	if(vis[v])return;
	vis[v]=1;
	if(p!=-1)d[v]=d[p]+1;
	for(auto i:g[v])dfs2(v,i);
}

int main(){FIN;
	ll n; cin>>n;
	ll root=-1;
	fore(i,0,n){
		ll p; cin>>p; p--;
		if(p==-1)root=i;
		else g[p].pb(i);
		cin>>c[i];
	}
	//cout<<root<<" ";
	fore(i,0,n){
		mset(vis,0);
		dfs(i,i);
	}
	/*fore(i,0,n){
	    for(auto j:gb[i])cout<<j<<" ";
	    cout<<"\n";
	}*/
	mset(vis,0);
	dfs2(-1,root);
	//fore(i,0,n)cout<<d[i]<<" ";
	fore(i,0,n){
		inf.pb({SZ(ga[i])-c[i],d[i]});
	}
	//fore(i,0,n)cout<<inf[i].fst<<" "<<inf[i].snd<<"\n";
	while(SZ(res)<n){
		pair<ll,ll> va={INF,INF};
		ll vai=-1;
		fore(i,0,n){
			if(va>inf[i]){
				va=inf[i];
				vai=i;
			}
		}
		if(va.fst!=0){
			//for(auto i:res)cout<<i.fst<<" "<<i.snd<<"\n";
			cout<<"NO"; return 0;
		}
		res.pb({vai,n-SZ(res)});
		for(auto i:gb[vai]){
			if(inf[i].fst!=INF){
				inf[i].fst--;
			}
		}
		inf[vai]={INF,INF};
	}
	sort(ALL(res));
	cout<<"YES\n";
	for(auto i:res)cout<<i.snd<<" ";
	return 0;
}