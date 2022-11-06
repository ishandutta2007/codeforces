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

ll getm(ll x, ll y){
	if(x>y)return -1;
	ll maxi=-1;	
	fore(i,0,23){
		if((x&(1ll<<i))&&!(y&(1ll<<i))){
			maxi=max(maxi,i);
		}
	}
	if(maxi==-1)return 0;
	ll b=-1;
	fore(i,maxi+1,23){
		if(!(x&(1ll<<i))&&(y&(1ll<<i))){
			b=i; break;
		}
	}
	assert(b!=-1);
	return (1ll<<b)-x%(1ll<<b);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b; cin>>a>>b;
		ll res=b-a;
		fore(i,0,2*b+1){
			ll am=getm(a,i);
			ll bm=getm(b,i);
			if(am==-1||bm==-1)continue;
			res=min(res,am+bm+(i-(b+bm))+1);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}