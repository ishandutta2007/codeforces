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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> vis(n);
		fore(i,0,m){
			ll a,b,c; cin>>a>>b>>c; a--; b--; c--;
			vis[b]=1;
		}
		ll ve=-1;
		fore(i,0,n){
			if(vis[i]==0)ve=i;
		}
		fore(i,0,n){
			if(i!=ve){
				cout<<i+1<<" "<<ve+1<<"\n";
			}
		}
	}
	
	return 0;
}