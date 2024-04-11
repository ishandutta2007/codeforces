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
		ll br=0;
		fore(i,2,32){
			if(n%((1ll<<i)-1)==0){
				cout<<n/((1ll<<i)-1)<<"\n"; br++;
				break;
			}
		}
		if(!br)assert(0);
	}
	
	return 0;
}