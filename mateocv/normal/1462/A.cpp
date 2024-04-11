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
		deque<ll> d;
		fore(i,0,n){
			ll a; cin>>a;
			d.pb(a);
		}
		ll va=0;
		while(SZ(d)){
			if(!va){
				cout<<d.front()<<" ";
				d.pop_front();
			}else{
				cout<<d.back()<<" ";
				d.pop_back();
			}
			va^=1;
		}
		cout<<"\n";
	}
	
	return 0;
}