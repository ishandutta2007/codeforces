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

const ll MOD=1000000007;

ll lcm(ll a, ll b){
	return a*(b/__gcd(a,b));
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll res=0;
		ll va=1;
		fore(i,2,101){
			res+=((n/va)-(n/lcm(va,i)))*i;
			va=lcm(va,i);
			if(va>n)break;
		}
		cout<<res%MOD<<"\n";
	}
	
	
	return 0;
}