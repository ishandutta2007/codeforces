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

ll sum(ll n){
	return n*(n+1)/2;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll x; cin>>x;
		ll van=0,res=0;
		fore(i,0,61){
			ll s=sum((1ll<<(i+1))-1);
			if(van+s<=x){
				res++;
				van+=s;
			}else{
				break;
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}