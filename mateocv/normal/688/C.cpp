#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> g[100005];
ll vis[100005];
vector<ll> res[2];
ll c[100005];

ll bfs(ll v){
	if(vis[v])return -2;
	queue<ll> q;
	q.push(v);
	vis[v]=1;
	if(c[v]!=-1)return -1;
	c[v]=0;
	res[0].pb(v);
//	cout<<"HOLA\n";
	while(SZ(q)>0){
		ll t=q.front(); q.pop();
		for(auto i:g[t]){
			if(!vis[i])q.push(i),vis[i]=1;
			if(c[i]!=-1&&c[i]!=(c[t]+1)%2)return -1;
			if(c[i]==(c[t]+1)%2)continue;
			c[i]=(c[t]+1)%2;
			res[c[i]].pb(i);
		//	cout<<"HOLA\n";
		}
	}
	return 0;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll u,v;
	fore(i,0,m){
		cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	mset(c,-1);
	fore(i,0,n){
		if(bfs(i)==-1){
			cout<<-1; return 0;
		}
	}
	cout<<SZ(res[0])<<"\n";
	for(auto i:res[0])cout<<i+1<<" "; cout<<"\n";
	cout<<SZ(res[1])<<"\n";
	for(auto i:res[1])cout<<i+1<<" "; cout<<"\n";
	
	return 0;
}