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

map<ll,ll> mp;
vector<pair<ll,ll>> res;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[2*n];
		fore(i,0,2*n)cin>>a[i];
		sort(a,a+2*n);
		ll br=0;
		fore(i,0,2*n-1){
			mp.clear();
			res.clear();
			fore(j,0,2*n-1){
				if(j!=i){
					if(mp.count(a[j]))mp[a[j]]++;
					else mp[a[j]]=1;
				}
			}
			res.pb({a[2*n-1],a[i]});
			ll va=a[2*n-1];
			while(SZ(mp)){
				auto it=mp.end();
				it--;
				ll g=it->fst;
				if(!mp.count(va-g)){
					break;
				}else{
					mp[va-g]--;
					if(mp[va-g]==0)mp.erase(va-g);
					if(!mp.count(g))break;
					mp[g]--;
					if(mp[g]==0)mp.erase(g);
					res.pb({g,va-g});
					va=g;
				}
			}
			if(SZ(mp)==0){
				br++; break;
			}
		}
		if(br){
			cout<<"YES\n"<<res[0].fst+res[0].snd<<"\n";
			for(auto i:res)cout<<i.fst<<" "<<i.snd<<"\n";
		}else{
			cout<<"NO\n";
		}
	}
	
	return 0;
}