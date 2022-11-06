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
		vector<vector<ll>> v(n);
		fore(i,0,n){
			v[i].resize(m);
			fore(j,0,m)cin>>v[i][j];
		}
		vector<ll> d(m);
		fore(i,0,n){
			auto s=v[i];
			sort(ALL(s));
			fore(j,0,m){
				if(s[j]!=v[i][j])d[j]++;
			}
		}
		ll c=0;
		for(auto i:d)c+=(i>0);
		if(c==0){
			cout<<"1 1\n";
		}else if(c>2){
			cout<<"-1\n";
		}else{
			vector<ll> res;
			fore(j,0,m){
				if(d[j])res.pb(j);
			}
			assert(SZ(res)==2);
			ll br=0;
			fore(i,0,n){
				swap(v[i][res[0]],v[i][res[1]]);
				auto s=v[i];
				sort(ALL(s));
				if(s!=v[i])br++;
			}
			if(!br)cout<<res[0]+1<<" "<<res[1]+1<<"\n";
			else cout<<"-1\n";
		}
	}
	
	return 0;
}