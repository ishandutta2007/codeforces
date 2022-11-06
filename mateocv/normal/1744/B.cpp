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
		ll n,q; cin>>n>>q;
		ll s=0;
		ll c[2]={0,0};
		fore(i,0,n){
			ll x; cin>>x;
			s+=x;
			c[x&1]++;
		}
		while(q--){
			ll ty,x; cin>>ty>>x;
			s+=c[ty]*x;
			if(x&1){
				c[ty^1]+=c[ty];
				c[ty]=0;
			}
			cout<<s<<"\n";
		}
	}
	
	return 0;
}