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
ll p[1010];

void bfs(ll v) {
	mset(vis,0);
	mset(d,0);
	mset(p,0);
	queue<int>q;
	vis[v]=1;
	p[v]=-1;
	q.push(v);
	while(q.size()) {
		int t=q.front(); q.pop();
		for(int i:g[t]) {
			if(!vis[i]) {
				vis[i]=1;
				q.push(i);
				d[i]=d[t]+1;
				p[i]=t;
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
		vector<pair<ll,ll>> resp;
		resp.pb(ask(v));
		ll dist=resp.back().snd;
		ll s=-1;
		ll maxd=0;
		fore(i,0,n){
			bfs(i);
			maxd=0;
			fore(j,0,n)maxd=max(maxd,d[j]);
			if(maxd<510){
				s=i; break;
			}
		}
		bfs(s);
		ll alt=0;
		pair<ll,ll> res={-1,-1};
		ll bus=0;
		for(ll i=9;i>=0;i--){
			if((1<<i)>maxd)continue;
			v.clear();
			fore(j,0,n){
				if(((1<<i)&d[j])&&(d[j]/(1<<(i+1))==alt/(1<<(i+1))))v.pb(j);
			}
			resp.pb(ask(v));
			if(resp.back().snd==dist){
				alt+=(1<<i);
			}
			if(i==0){
				if(resp.back().fst==-1)bus++;
				else if(resp.back().snd==dist){
					res.fst=resp.back().fst;
				}else{
					ll br=0;
					for(auto j:resp){
						if(d[j.fst]==alt&&j.snd==dist){
							res.fst=j.fst;
							br++; break;
						}
					}
					assert(br);
				}
			}
		}
		//cout<<alt<<endl;
		if(bus){
			vector<ll> h;
			fore(i,0,n){
				if(d[i]==alt)h.pb(i);
			}
			res.fst=ask(h).fst;
		}
		bfs(res.fst);
		vector<ll> hh;
		fore(i,0,n){
			if(d[i]==dist)hh.pb(i);
		}
		res.snd=ask(hh).fst;
		cout<<"! "<<res.fst+1<<" "<<res.snd+1<<endl;
		string respp; cin>>respp;
		assert(respp=="Correct");
		fore(i,0,n)g[i].clear();
	}
	
	return 0;
}