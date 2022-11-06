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

ll ask(ll t, ll i, ll j, ll x){
	cout<<"? "<<t<<" "<<i+1<<" "<<j+1<<" "<<x<<endl;
	ll resp; cin>>resp;
	if(resp==-1)exit(0);
	return resp;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll pos=-1;
		fore(i,0,n/2){
			ll a=ask(2,2*i,2*i+1,1);
			if(a==1){
				pos=2*i;
				break;
			}else if(a==2){
				a=ask(2,2*i+1,2*i,1);
				if(a==1){
					pos=2*i+1;
					break;
				}
			}
		}
		if(pos==-1&&n%2==1){
			pos=n-1;
		}
		assert(pos!=-1);
		vector<ll> res;
		fore(i,0,n){
			if(i==pos){
				res.pb(1);
			}else{
				res.pb(ask(1,pos,i,n-1));
			}
		}
		cout<<"! ";
		for(auto i:res)cout<<i<<" ";
		cout<<endl;
	}
	
	return 0;
}