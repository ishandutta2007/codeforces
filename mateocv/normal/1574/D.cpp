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
typedef int ll;

int main(){FIN;
	ll n; cin>>n;
	vector<vector<ll>> v(n);
	fore(i,0,n){
		ll k; cin>>k;
		v[i].resize(k);
		fore(j,0,k)cin>>v[i][j];
	}
	set<vector<ll>> b;
	ll m; cin>>m;
	fore(i,0,m){
		vector<ll> vb(n);
		fore(i,0,n)cin>>vb[i],vb[i]--;
		b.insert(vb);
	}
	set<pair<ll,vector<ll>>> st;
	ll s=0;
	for(auto i:v)s+=i.back();
	vector<ll> vi;
	fore(i,0,n)vi.pb(SZ(v[i])-1);
	st.insert({-s,vi});
	while(1){
		auto f=*st.begin();
		st.erase(f);
		if(!b.count(f.snd)){
			for(auto i:f.snd){
				cout<<i+1<<" ";
			}
			cout<<"\n";
			return 0;
		}else{
			fore(i,0,n){
				if(f.snd[i]){
					auto ff=f;
					ff.snd[i]--;
					ff.fst+=v[i][f.snd[i]];
					ff.fst-=v[i][f.snd[i]-1];
					st.insert({ff});
				}
			}
		}
	}
	
	return 0;
}