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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		if(n&1){
			cout<<"NO\n";
		}else{
			sort(ALL(a));
			vector<ll> b[2];
			fore(i,0,n){
				b[i>=n/2].pb(a[i]);
			}
			auto maxi=b[1].back();
			b[1].pop_back();
			reverse(ALL(b[1]));
			b[1].pb(maxi);
			reverse(ALL(b[0]));
			vector<ll> res;
			fore(i,0,n/2){
				res.pb(b[0][i]);
				res.pb(b[1][i]);
			}
			ll br=0;
			fore(i,0,n){
				if(res[i]==res[(i+1)%n])br++;
			}
			//for(auto i:res)cout<<i<<" ";
			//cout<<"\n";
			if(br)cout<<"NO\n";
			else {
				cout<<"YES\n";
				for(auto i:res)cout<<i<<" ";
				cout<<"\n";
			}
		}
	}
	
	return 0;
}