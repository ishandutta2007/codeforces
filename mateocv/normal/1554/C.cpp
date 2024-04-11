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
		ll n,m; cin>>n>>m;
		ll res=1e18;
		fore(i,0,31){
			if(!(m&(1<<i))){
				ll mk=(m>>i);
				mk^=1;
				mk<<=i;
				mk^=(n&((1ll<<i)-1));
				res=min(res,mk^n);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}