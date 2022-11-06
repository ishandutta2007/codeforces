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

const ll MOD=998244353;
//const ll N=300050;
vector<ll> g[300004];
ll vis[300004];
//unordered_set<ll> s;

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

ll solve(ll x) {
	queue<int>q;
	ll r[2]={0,0};
	q.push(x);
	vis[x]=1; r[1]++;
	while(q.size()) {
		int t=q.front(); q.pop();
//		cout<<t+1<<" ";
		for(ll i:g[t]) {
			if(vis[i]==vis[t]){
				return 0;
			}else if(!vis[i]){
				q.push(i);
				if(vis[t]==1){
					vis[i]=2; r[0]++;
				}else{
					vis[i]=1; r[1]++;
				}
			}
		}
	}
	ll res=0;
	res+=be(2,r[0],MOD);
	res+=be(2,r[1],MOD);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		//for(auto i:s)g[i].clear();
		//s.clear();
		//vector<ll> g[300004];
		fore(i,0,n)vis[i]=0;
		ll a,b;
		fore(i,0,m){
			cin>>a>>b;
			a--; b--;
			g[a].pb(b);
			g[b].pb(a);
		//	s.insert(a);
		//	s.insert(b);
		}
		ll res=1;
		fore(i,0,n){
			if(!vis[i]){
				res*=solve(i);
				res%=MOD;
			}
		}
		cout<<res<<"\n";
		fore(i,0,n)g[i].clear();
	}
	
	return 0;
}