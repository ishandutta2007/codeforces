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

vector<ll> g[100005];
set<ll> s; ll tot=0;
ll vis[100005];

void solve(){
	if(tot==0){
		cout<<1<<" ";
		vis[0]=1;
		for(auto i:g[0]){
			if(!vis[i])s.insert(i);
		}
		tot++; return;
	}
	for(auto i:s){
		cout<<i+1<<" ";
		vis[i]=1;
		for(auto j:g[i]){
			if(!vis[j])s.insert(j);
		}
		s.erase(i);
		tot++; return;
	}
	
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a,b;
	memset(vis,0,sizeof vis);
	fore(i,0,m){
		cin>>a>>b;
		if(a!=b){
			a--; b--;
			g[a].pb(b);
			g[b].pb(a);
		}
	}
	while(tot<n){
		solve();
	}
	
	return 0;
}