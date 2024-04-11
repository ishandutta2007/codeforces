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
		ll a[n];
		fore(i,0,n)cin>>a[i],a[i]--;
		ll tot=0;
		fore(i,0,n){
			tot+=(a[i]==i);
		}
		if(tot==n){
			cout<<0<<"\n";
		}else if(tot==0){
			cout<<1<<"\n";
		}else{
			vector<ll> v;
			fore(i,0,n){
				if(a[i]!=i)v.pb(i);
			}
			if(v.back()-v[0]==SZ(v)-1){
				cout<<1<<"\n";
			}else{
				cout<<2<<"\n";
			}
		}
	}
	
	return 0;
}