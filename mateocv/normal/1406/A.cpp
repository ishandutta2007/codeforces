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
		ll c[105];
		mset(c,0);
		fore(i,0,n){
			ll lle; cin>>lle;
			c[lle]++;
		}
		ll res=0;
		fore(i,0,101){
			if(c[i]<2){
				res+=i; break;
			}	
		}
		fore(i,0,101){
			if(c[i]<1){
				res+=i; break;
			}	
		}
		cout<<res<<"\n";
	}
	
	return 0;
}