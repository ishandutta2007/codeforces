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
		string s; cin>>s;
		ll w,m; cin>>w>>m;
		vector<ll> sump={0};
		for(auto i:s){
			sump.pb((sump.back()+i-'0')%9);
		}
		vector<ll> oc[10];
		fore(i,0,SZ(s)-w+1){
			oc[(sump[i+w]+9-sump[i])%9].pb(i);
			//cout<<(sump[i+w]+9-sump[i])%9<<" "<<i<<"\n";
		}
		while(m--){
			ll l,r,k; cin>>l>>r>>k; l--;
			ll val=(sump[r]+9-sump[l])%9;
			pair<ll,ll> res={SZ(s),SZ(s)};
			fore(i,0,10){
				fore(j,0,10){
					if((i*val+j)%9==k){
						if(i==j&&SZ(oc[i])>=2){
							res=min(res,{oc[i][0],oc[i][1]});
						}else if(i!=j&&SZ(oc[i])>=1&&SZ(oc[j])>=1){
							res=min(res,{oc[i][0],oc[j][0]});
						}
					}
				}
			}
			if(res.fst==SZ(s))cout<<"-1 -1\n";
			else cout<<res.fst+1<<" "<<res.snd+1<<"\n";
		}
	}
	
	return 0;
}