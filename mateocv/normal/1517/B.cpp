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
		vector<pair<ll,ll>> v;
		fore(i,0,n){
			fore(j,0,m){
				ll x; cin>>x;
				v.pb({x,i});
			}
		}
		//for(auto i:v)cout<<i.fst<<" "<<i.snd<<endl;
		sort(ALL(v));
		vector<vector<ll>> vf(n);
		while(SZ(v)>m){
			auto b=v.back();
			vf[b.snd].pb(b.fst);
			v.pop_back();
		}
		/*
		fore(j,0,n){
			for(auto i:vf[j])cout<<i<<" ";
			cout<<endl;
		}
		*/
		vector<vector<ll>> res(n);
		while(SZ(v)){
			auto b=v.back();
			v.pop_back();
			res[b.snd].pb(b.fst);
			fore(i,0,n){
				if(i!=b.snd){
					assert(SZ(vf[i]));
					res[i].pb(vf[i].back());
					vf[i].pop_back();
				}
			}
		}
		fore(i,0,n){
			for(auto j:res[i])cout<<j<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}