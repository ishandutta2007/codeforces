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

const int MAXN=200005;

vector<ll> oc[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> vis;
		fore(i,0,n){
			ll x; cin>>x; x--;
			oc[x].pb(i);
			vis.pb(x);
		}
		sort(ALL(vis));
		vis.erase(unique(ALL(vis)), vis.end());
		ll res=0;
		for(auto i:vis){
			fore(j,0,SZ(oc[i])-1){
				res=max(res,oc[i][j]+n-oc[i][j+1]);
			}
		}
		if(res==0)cout<<"-1\n";
		else cout<<res<<"\n";
		for(auto i:vis)oc[i].clear();
	}
	
	return 0;
}