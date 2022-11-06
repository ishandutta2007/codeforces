#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

bool sq(ll n){
	ll s=sqrt(n);
	fore(i,max(0ll,s-5),s+5){
		if(i*i==n)return 1;
	}
	return 0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n&1){
			cout<<"NO\n";
		}else{
			if(sq(n)||sq(n/2))cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	
	return 0;
}