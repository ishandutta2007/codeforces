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

vector<pair<ll,ll>> v;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		v.clear();
		fore(i,0,m){
			ll x,y; cin>>x>>y; x--; y--;
			v.pb({y,x});
		}
		sort(ALL(v));
		ll pr=-1,br=0;
		if(SZ(v)&1){
			br++;
		}else{
			while(SZ(v)){
				auto a=v.back(); v.pop_back();
				auto b=v.back(); v.pop_back();
				if(a.fst==pr){
					br++; break;
				}
				if(a.fst==b.fst){
					pr=-1;
					continue;
				}
				if(a.snd==b.snd){
					if((a.fst&1)!=(b.fst&1)){
						pr=b.fst;
					}else{
						br++; break;
					}
				}else{
					if((a.fst&1)==(b.fst&1)){
						pr=b.fst;
					}else{
						br++; break;
					}
				}
			}
		}
		if(br){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}
	}
	
	return 0;
}