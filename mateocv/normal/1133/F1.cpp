#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> g[200005];
ll vis[200005];

void bfs(ll x) {
	queue<int>q;
	q.push(x);
	vis[x]=1;
	while(q.size()) {
		int t=q.front(); q.pop();
		//cout<<t+1<<" ";
		for(ll i:g[t]) {
			if(!vis[i]) {
				vis[i]=1;
				q.push(i);
				cout<<t+1<<" "<<i+1<<"\n";
			}
		}
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a,b;
	memset(vis,0,sizeof vis);
	ll deg[n];
	memset(deg,0,sizeof deg);
	fore(i,0,m){
		cin>>a>>b; a--; b--;
		g[a].pb(b);
		g[b].pb(a);
		deg[a]++; deg[b]++;
	}
	ll maxi=0, maxid=-1;
	fore(i,0,n){
		if(deg[i]>maxi){
			maxi=deg[i];
			maxid=i;
		}
	}
	bfs(maxid);
	
	
	return 0;
}