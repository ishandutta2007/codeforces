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

ll val=100000;

ll cant(ll a, ll b, ll k){
	ll res=max(min(a/k,(b+1))-a/(k+1)-1+1,0ll);
	//if(res>0)cout<<"cant "<<a<<" "<<b<<" "<<k<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b; cin>>a>>b;
		ll res=0;
		fore(i,1,b+1){
			if(a/(i+1)<=val)res-=a/(i+1);
			res+=min(a/(i+1),i-1);
			if(a/(i+1)<i-1)break;
		}
		fore(i,1,val+1){
			res+=cant(a,b,i)*i;
		}
		if(a<=val)res-=a;
		cout<<res<<"\n";
	}
	
	return 0;
}