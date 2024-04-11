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

vector<ll> g[MAXN];

ll vis[MAXN],d[MAXN];

void bfs(ll v) {
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
		ll n,a,b,da,db; cin>>n>>a>>b>>da>>db; a--; b--;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		fore(i,0,n)vis[i]=0,d[i]=0;
		bfs(0);
		ll maxid=0,maxiv=0;
		fore(i,0,n){
			if(d[i]>maxid){
				maxid=d[i];
				maxiv=i;
			}
		}
		fore(i,0,n)vis[i]=0,d[i]=0;
		bfs(maxiv);
		maxid=0,maxiv=0;
		fore(i,0,n){
			if(d[i]>maxid){
				maxid=d[i];
				maxiv=i;
			}
		}
		ll dm=(maxid+1)/2;
		fore(i,0,n)vis[i]=0,d[i]=0;
		bfs(a);
		if(da>=dm||d[b]<=da||db<=2*da){
			cout<<"Alice\n";
		}else{
			cout<<"Bob\n";
		}
		fore(i,0,n)g[i].clear();
	}
	
	return 0;
}