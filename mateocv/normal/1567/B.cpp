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
	vector<ll> xp={0};
	fore(i,1,300005)xp.pb(xp.back()^i);
	ll t; cin>>t;
	while(t--){
		ll a,b; cin>>a>>b;
		ll x=xp[a-1];
		if((b^x)==0)cout<<a<<"\n";
		else if((b^x)!=a)cout<<a+1<<"\n";
		else cout<<a+2<<"\n";
	}
	
	return 0;
}