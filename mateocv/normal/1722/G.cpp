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
		vector<ll> res(n);
		fore(i,0,n-1){
			res[i]^=i;
			res.back()^=i;
		}
		ll pos=-1;
		fore(i,0,n-1){
			if(res[i]==res.back())pos=i;
		}
		ll ot=-1;
		fore(i,0,3){
			if(i!=n-1&&i!=pos){
				ot=i;
			}
		}
		res[ot]^=(1ll<<30);
		res.back()^=(1ll<<30);
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}