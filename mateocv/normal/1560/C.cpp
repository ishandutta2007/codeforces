#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll k; cin>>k;
		ll sq=-1;
		fore(i,0,100001){
			if(i*i<k&&k<=(i+1)*(i+1)){
				sq=i; break;
			}
		}
		k-=sq*sq;
		if(k<=sq+1){
			cout<<k<<" "<<sq+1<<"\n";
		}else{
			cout<<sq+1<<" "<<2*sq+2-k<<"\n";
		}
	}
	
	return 0;
}