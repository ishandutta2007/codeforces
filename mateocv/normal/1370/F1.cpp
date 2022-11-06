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

vector<ll> g[1010];

pair<ll,ll> ask(vector<ll> v){
	if(SZ(v)==0){
		return {-1,0};
	}
	cout<<"? "<<SZ(v)<<" ";
	for(auto i:v)cout<<i+1<<" ";
	cout<<endl;
	pair<ll,ll> resp; cin>>resp.fst>>resp.snd;
	resp.fst--;
	return resp;
}

ll vis[1010];
ll d[1010];

void bfs(ll v) {
	mset(vis,0);
	mset(d,0);
	queue<int>q;
	vis[v]=1;
	q.push(v);
	while(q.size()) {
		int t=q.front(); q.pop();
		for(int i:g[t]) {
			if(!vis[i]) {
				vis[i]=1;
				q.push(i);
				d[i]=d[t]+1;
			}
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		vector<ll> v;
		fore(i,0,n)v.pb(i);
		ll dist=ask(v).snd;
		bfs(0);
		ll maxd=0;
		fore(i,0,n)maxd=max(maxd,d[i]);
		ll alt=0;
		for(ll i=9;i>=0;i--){
			if((1<<i)>maxd)continue;
			v.clear();
			fore(j,0,n){
				if(((1<<i)&d[j])&&(d[j]/(1<<(i+1))==alt/(1<<(i+1))))v.pb(j);
			}
			auto a=ask(v);
			if(a.snd==dist){
				alt+=(1<<i);
			}
		}
		//cout<<alt<<endl;
		vector<ll> h;
		fore(i,0,n){
			if(d[i]==alt)h.pb(i);
		}
		pair<ll,ll> res={-1,-1};
		res.fst=ask(h).fst;
		bfs(res.fst);
		vector<ll> hh;
		fore(i,0,n){
			if(d[i]==dist)hh.pb(i);
		}
		res.snd=ask(hh).fst;
		cout<<"! "<<res.fst+1<<" "<<res.snd+1<<endl;
		string resp; cin>>resp;
		assert(resp=="Correct");
		fore(i,0,n)g[i].clear();
	}
	
	return 0;
}