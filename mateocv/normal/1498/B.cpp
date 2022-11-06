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
		ll n,w; cin>>n>>w;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll c[22];
		mset(c,0);
		fore(i,0,n){
			fore(j,0,22){
				if(a[i]==(1ll<<j)){
					c[j]++;
				}
			}
		}
		ll res=0,tot=n;
		while(tot){
			ll va=w;
			for(ll i=21;i>=0;i--){
				while((1ll<<i)<=va&&c[i]){
					va-=(1ll<<i);
					c[i]--;
					tot--;
				}
			}
			res++;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}