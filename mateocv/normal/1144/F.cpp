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

vector<pair<ll,ll>> g[200005];
ll vis[200005];
ll col[200005];
ll res[200005];
ll m;

ll bfs(ll x) {
	queue<pair<ll,ll>>q;
	vis[x]=1;
	q.push({x,0});
	while(q.size()) {
		pair<ll,ll> t=q.front(); q.pop();
	//	cout<<t+1<<" ";
		for(auto i:g[t.fst]) {
			if(!vis[i.fst]) {
				vis[i.fst]=1;
				col[i.fst]=1-col[t.fst];
				if(col[t.fst]==0){
					if(i.snd>=m){
						res[i.snd-m]=0;
					}else{
						res[i.snd]=1;
					}
				}else{
					if(i.snd>=m){
						res[i.snd-m]=1;
					}else{
						res[i.snd]=0;
					}	
				}
				q.push(i);
			}else{
				if(col[i.fst]==col[t.fst])return 0;
				if(col[t.fst]==0){
					if(i.snd>=m){
						res[i.snd-m]=0;
					}else{
						res[i.snd]=1;
					}
				}else{
					if(i.snd>=m){
						res[i.snd-m]=1;
					}else{
						res[i.snd]=0;
					}	
				}
			}
		}
	}
	return 1;
}

int main(){FIN;
	ll n; cin>>n>>m;
	ll a,b;
	fore(i,0,m){
		cin>>a>>b;
		a--; b--;
		g[a].pb({b,i});//a->b 0
		g[b].pb({a,i+m});//b->a 1
	}
	mset(vis,0);
	mset(res,0);
	mset(col,0);
	if(bfs(0)){
		cout<<"YES\n";
		fore(i,0,m){
			cout<<res[i];
		}
	}else{
		cout<<"NO";
	}
	
	return 0;
}