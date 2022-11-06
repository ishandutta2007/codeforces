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

ll INF=1e18;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll res=-1;
		vector<ll> va={INF,INF,INF,INF,INF};
		vector<vector<ll>> vv;
		fore(i,0,n){
			vector<ll> v(5);
			fore(j,0,5)cin>>v[j];
			vv.pb(v);
			ll tot=0;
			fore(j,0,5){
				tot+=(v[j]<va[j]);
			}
			if(tot>=3){
				va=v;
				res=i;
			}
		}
		ll br=0;
		fore(i,0,n){
			ll tot=0;
			fore(j,0,5){
				tot+=(vv[i][j]<va[j]);
			}
			if(tot>=3){
				cout<<"-1\n";
				br++; break;
			}
		}
		if(!br)cout<<res+1<<"\n";
	}
	
	return 0;
}