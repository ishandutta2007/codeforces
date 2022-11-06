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

const int MAXN=1010;

vector<ll> g[MAXN];

ll vis[MAXN],p[MAXN];

vector<ll> ord;

void dfs(ll v){
	vis[v]=1;
	ord.pb(v);
	for(auto i:g[v]){
		if(!vis[i]){
			p[i]=v;
			dfs(i);
		}
	}
	ord.pb(v);
}

ll ask(vector<ll> v){
	cout<<"? "<<SZ(v)<<" ";
	for(auto i:v)cout<<i+1<<" ";
	cout<<endl;
	ll resp; cin>>resp;
	return resp;
}

vector<pair<ll,ll>> ed;

vector<ll> get(ll l, ll r){
	vector<ll> res;
	fore(i,l,r+1){
		res.pb(ed[i].fst);
		res.pb(ed[i].snd);
	}
	sort(ALL(res));
	res.erase(unique(ALL(res)), res.end());
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-1){
		ll x,y; cin>>x>>y; x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0);
	vector<ll> v;
	fore(i,0,n)v.pb(i);
	auto d=ask(v);
	for(auto i:ord){
		if(i!=0){
			ed.pb({i,p[i]});
		}
	}
	ll l=0,r=SZ(ed)-1;
	while(l<r){
		ll m=(l+r)/2;
		if(ask(get(l,m))==d)r=m;
		else l=m+1;
	}
	cout<<"! "<<ed[l].fst+1<<" "<<ed[l].snd+1<<"\n";
	
	return 0;
}