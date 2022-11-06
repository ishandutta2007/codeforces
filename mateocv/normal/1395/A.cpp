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

ll par(ll a, ll b, ll c, ll d){
	ll tot=0;
	tot+=(a&1);
	tot+=(b&1);
	tot+=(c&1);
	tot+=(d&1);
	return tot<=1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b,c,d; cin>>a>>b>>c>>d;
		if(par(a,b,c,d)||(min({a,b,c})>=1&&par(a-1,b-1,c-1,d+3))){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	
	return 0;
}