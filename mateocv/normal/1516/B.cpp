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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll x=0;
		fore(i,0,n)x^=a[i];
		if(x==0){
			cout<<"YES\n";
		}else{
			pair<ll,ll> pos={-1,-1};
			ll x0=0;
			fore(i,0,n){
				x0^=a[i];
				if(x0==x){
					pos.fst=i;
					break;
				}
			}
			x0=0;
			fore(i,0,n){
				x0^=a[n-1-i];
				if(x0==x){
					pos.snd=n-1-i;
					break;
				}
			}
			assert(pos.fst!=-1);
			if(pos.fst<pos.snd){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}
	}
	
	return 0;
}