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

ll form(ll n){
	return n*(n-1)/2;
}

ll cant(ll k, ll m){
	return (k%m)*form((k+m-1)/m)+(m-(k%m))*form(k/m);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m,d,w; cin>>m>>d>>w;
		ll g=__gcd(w,abs(d-1));
		w/=g;
		cout<<cant(min(m,d),w)<<"\n";
	}
	
	return 0;
}