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
		ll n,k; cin>>n>>k;
		vector<pair<ll,ll>> v;
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			v.pb({x,y});
		}
		ll br=0;
		fore(i,0,n){
			ll tot=0;
			fore(j,0,n){
				if(abs(v[i].fst-v[j].fst)+abs(v[i].snd-v[j].snd)<=k){
					tot++;
				}
			}
			if(tot<n)continue;
			else{
				br++; break;
			}
		}
		if(br){
			cout<<"1\n";
		}else{
			cout<<"-1\n";
		}
	}

	
	return 0;
}