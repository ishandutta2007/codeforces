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
		vector<ll> v;
		fore(i,0,n){
			ll lle; cin>>lle;
			v.pb(lle);
		}
		ll maxi=0,sum=0;
		fore(i,0,n)maxi=max(maxi,v[i]),sum+=v[i];
		if(maxi>sum-maxi){
			cout<<"T\n";
		}else{
			if(sum&1)cout<<"T\n";
			else cout<<"HL\n";
		}
	}
	
	return 0;
}