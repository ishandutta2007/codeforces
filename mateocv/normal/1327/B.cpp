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
		ll n; cin>>n;
		vector<vector<ll>> v;
		vector<ll> vv;
		ll vis[n];
		mset(vis,0);
		fore(i,0,n){
			ll k,g; cin>>k;
			fore(j,0,k)cin>>g,g--,vv.pb(g);
			v.pb(vv);
			vv.clear();
		} 
		ll us[n];
		mset(us,0);
		fore(i,0,n){
			for(auto j:v[i]){
				if(!vis[j]){
					vis[j]=1;
					us[i]=1;
					break;
				}
			}
		}
		ll br=0;
		fore(i,0,n){
			if(!us[i]){
				fore(j,0,n){
					if(!vis[j]){
						cout<<"IMPROVE\n"<<i+1<<" "<<j+1<<"\n"; br++; break;
					}
				}
			}
			if(br)break;
		}
		if(br)continue;
		cout<<"OPTIMAL\n";
	}
	
	return 0;
}