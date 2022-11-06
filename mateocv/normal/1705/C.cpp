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
		ll n,c,q; cin>>n>>c>>q;
		string s; cin>>s;
		vector<pair<ll,ll>> v(c);
		fore(i,0,c)cin>>v[i].fst>>v[i].snd;
		fore(i,0,c)v[i].fst--;
		ll va=n;
		vector<pair<ll,ll>> vp;
		for(auto i:v){
			vp.pb({va,va+i.snd-i.fst});
			va=vp.back().snd;
		}
		while(q--){
			ll k; cin>>k; k--;
			for(ll i=c-1;i>=0;i--){
				if(k>=vp[i].fst){
					k=v[i].fst+k-vp[i].fst;
				}
			}
			assert(k<n);
			cout<<s[k]<<"\n";
		}
	}
	
	return 0;
}