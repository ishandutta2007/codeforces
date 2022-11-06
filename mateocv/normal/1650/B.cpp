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

ll f(ll x, ll a){
	return x/a+(x%a);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll l,r,a; cin>>l>>r>>a;
		ll res=f(r,a);
		if((r/a)*a-1>=l)res=max(res,f((r/a)*a-1,a));
		cout<<res<<"\n";
	}
	
	return 0;
}