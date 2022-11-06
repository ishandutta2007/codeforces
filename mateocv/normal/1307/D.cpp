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
ll d[200005][2];

ll n;

void bfs(ll v, ll b) {
	queue<int>q;
	vis[v]=1;
	q.push(v);
	while(q.size()) {
		int t=q.front(); q.pop();
		for(int i:g[t]) {
			if(!vis[i]) {
				vis[i]=1;
				q.push(i);
				d[i][b]=d[t][b]+1;
			}
		}
	}
}

bool cmp(const ll &u,const ll &v){
	return d[u][0]<d[v][0];
}

int main(){FIN;
	ll m,k; cin>>n>>m>>k;
	ll a[k];
	fore(i,0,k)cin>>a[i],a[i]--;
	ll u,v;
	fore(i,0,m){
		cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	bfs(0,0);
	mset(vis,0);
	bfs(n-1,1);
	//fore(i,0,n)cout<<d[i]<<" "; cout<<"\n";
	sort(a,a+k,cmp);
	//fore(i,0,k)cout<<a[i]<<" "; cout<<"\n";
	ll res=0;
	fore(i,0,k-1){
		res=max(res,min(d[0][1],d[a[i]][0]+d[a[i+1]][1]+1));
		//cout<<d[n-1]-(d[a[i+1]]-d[a[i]]+1)<<"\n";
	}
	cout<<res;
	return 0;
}