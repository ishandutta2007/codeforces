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

bool val(ll n){
	ll va=n;
	while(va){
		ll d=va%10;
		if(d!=0&&n%d!=0)return false;
		va/=10;
	}
	return true;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll br=0;
		fore(i,0,2ll*2520){
			if(val(n+i)){
				cout<<n+i<<"\n";
				br++; break;
			}
		}
		assert(br);
	}
	
	return 0;
}