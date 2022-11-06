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

const int MAXN=200005;

vector<ll> g[MAXN];

bool vis[MAXN];
ll c[MAXN];

void bfs() {
	queue<int>q;
	vis[0]=1;
	q.push(0);
	c[0]=0;
	while(q.size()) {
		int t=q.front(); q.pop();
		for(int i:g[t]) {
			if(!vis[i]) {
				vis[i]=1;
				c[i]=c[t]^1;
				q.push(i);
			}
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		fore(i,0,n)g[i].clear();
		fore(i,0,n)vis[i]=0,c[i]=0;
		fore(i,0,m){
			ll v,u; cin>>v>>u; v--; u--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll s=0;
		for(auto i:a)s+=i;
		for(auto i:b)s+=i;
		if(s&1){
			cout<<"NO\n";
			continue;
		}
		bfs();
		ll bp=1;
		fore(i,0,n){
			for(auto j:g[i]){
				if(c[i]==c[j])bp=0;
			}
		}
		ll sa=0,sb=0;
		fore(i,0,n){
			if(c[i]==1)sa+=a[i],sb+=b[i];
			else sa-=a[i],sb-=b[i];
		}
		if(bp){
			if(sa==sb)cout<<"YES\n";
			else cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}
	}
	
	return 0;
}