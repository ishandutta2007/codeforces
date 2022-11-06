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
		ll n,m; cin>>n>>m;
		vector<ll> c(n);
		fore(i,0,m){
			ll x; cin>>x; x--;
			c[x]++;
		}
		ll l=0,r=2*m;
		while(l<=r){
			ll m=(l+r)/2;
			ll va=0;
			fore(i,0,n){
				if(c[i]<=m){
					va+=(m-c[i])/2;
				}else{
					va-=c[i]-m;
				}
			}
			if(va>=0)r=m-1;
			else l=m+1;
		}
		cout<<l<<"\n";
	}
	
	return 0;
}