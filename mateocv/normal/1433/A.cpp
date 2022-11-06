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

ll dig(ll n){
	return SZ(to_string(n));
}

vector<ll> v;

int main(){FIN;
	fore(i,1,10){
		ll va=i;
		fore(j,0,4){
			v.pb(va);
			va=10*va+i;
		}
	}
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll res=0;
		for(auto i:v){
			res+=dig(i);
			if(i==n)break;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}