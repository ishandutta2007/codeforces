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
		ll n,g,b; cin>>n>>g>>b;
		if(g>=b){
			cout<<n<<"\n";
		}else{
			ll res=(((n+1)/2)/g)*(g+b)-b;
			ll f=b*(((n+1)/2)/g-1);
			if(((n+1)/2)%g!=0){
				res+=b+((n+1)/2)%g;
				f+=b;
				if(f<n/2){
					cout<<n<<"\n"; continue;
				}else{
					cout<<res<<"\n";
				}
			}else{
				if(f<n/2){
					cout<<n<<"\n";
				}else{
					cout<<res<<"\n";
				}
			}
			
		}
	}
	
	return 0;
}