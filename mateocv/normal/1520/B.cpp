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

vector<ll> v;

int main(){FIN;
	v.pb(1);
	fore(i,0,9)v.pb(10*v.back()+1);
	fore(i,0,9){
		fore(j,2,10){
			v.pb(v[i]*j);
		}
	}
	sort(ALL(v));
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,SZ(v)){
			if(n<v[i]){
				cout<<i<<"\n";
				break;
			}
		}
	}
	
	return 0;
}