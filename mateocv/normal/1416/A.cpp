#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> g[300005];
ll a[300005];
ll res[300005];
ll INF=(1ll<<60);

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)g[i].pb(0);
		fore(i,0,n)g[a[i]].pb(i+1);
		fore(i,0,n)g[i].pb(n+1);
		fore(i,0,n)res[i]=INF;
		fore(i,0,n){
			ll maxi=0;
			fore(j,0,SZ(g[i])-1){
				maxi=max(maxi,g[i][j+1]-g[i][j]);
			}
			//cout<<i<<": "<<maxi<<"\n";
			maxi--;
			res[maxi]=min(i,res[maxi]);
		}
		fore(i,0,n){
			if(i>0){
				res[i]=min(res[i],res[i-1]);
			}
			if(res[i]==INF){
				cout<<"-1 ";
			}else{
				cout<<res[i]+1<<" ";
			}
		}
		cout<<"\n";
		fore(i,0,n)g[i].clear();
	}
	
	return 0;
}