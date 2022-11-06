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

vector<ll> g[200005];

ll vis[200005];
ll d[200005];
ll p[200005];
ll us[200005];
ll h[200005];

void bfs() {
	queue<int>q;
	vis[0]=1;
	q.push(0);
	p[0]=-1;
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

ll vis2[200005];

void dfs(ll v){
	vis2[v]=1;
	h[v]=1;
	for(auto i:g[v]){
		if(!vis2[i]){
			dfs(i);
			h[v]+=h[i];	
		}
	}
}

bool cpm(ll u, ll v){
	return d[u]-h[u]<d[v]-h[v]||(d[u]-h[u]==d[v]-h[v]&&u<v);
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	bfs();
	dfs(0);
	vector<ll> a;
	fore(i,0,n)a.pb(i);
	sort(ALL(a),cpm);
//	for(auto i:a)cout<<i<<" ";
	ll res=0;
	while(k--){
		ll b=a.back();
//		cout<<a.back()<<"\n";
		res+=d[b]-h[b]+1;
		a.pop_back();
	}
	/*fore(i,0,n){
		if(us[i]&&p[i]!=-1&&!us[p[i]]){
			res+=d[i]*h[i];
		}
	}*/
	cout<<res;
	return 0;
}