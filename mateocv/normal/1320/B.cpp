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
vector<ll> gr[200005];
ll vis[200005];
ll d[200005];

void bfs(ll v) {
	queue<int>q;
	vis[v]=1;
	q.push(v);
	while(q.size()) {
		int t=q.front(); q.pop();
		//cout<<t+1<<" ";
		for(int i:gr[t]) {
			if(!vis[i]) {
				vis[i]=1;
				d[i]=d[t]+1;
				q.push(i);
			}
		}
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll u,v;
	fore(i,0,m){
		cin>>u>>v; u--; v--;
		g[u].pb(v);
		gr[v].pb(u);
	}
	ll k; cin>>k;
	ll p[k];
	fore(i,0,k)cin>>p[i],p[i]--;
	bfs(p[k-1]);
	//fore(i,0,n)cout<<d[i]<<" "; cout<<"\n";
	ll res[2]={0,0};
	fore(i,0,k-1){
		if(d[p[i]]<=d[p[i+1]])res[0]++,res[1]++;//,cout<<i<<" ";
		else{
			for(auto j:g[p[i]]){
				if(d[j]<d[p[i]]&&j!=p[i+1]){
					res[1]++; break;
				}
			}
		}
	}
	cout<<res[0]<<" "<<res[1];
	return 0;
}