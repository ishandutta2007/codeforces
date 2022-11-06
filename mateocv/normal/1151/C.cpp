#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MOD=1ll*1e9+7;

ll parc(ll x){
	if(x==0)return 0;
	ll imp=0,par=0;
	fore(i,0,62){
		if(x>=(1LL<<i)){
			if(i%2){
				par+=(1LL<<i);
			}else{
				imp+=(1LL<<i);
			}
			x-=(1LL<<i);
		}else{
			if(i%2){
				par+=x;
			}else{
				imp+=x;
			}
			break;
		}
	}
	imp%=MOD; par%=MOD;
	return (imp*imp+par*par+par)%MOD;
}

int main(){FIN;
	ll l,r; cin>>l>>r;
	cout<<(parc(r)-parc(l-1)+MOD)%MOD;
	
	return 0;
}