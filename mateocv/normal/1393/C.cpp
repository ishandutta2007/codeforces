#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
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
		fore(i,0,n){
			cin>>a[i];
		}
		map<ll,ll> mp;
		fore(i,0,n){
			mp[a[i]]++;
		}
		vector<ll> v;
		for(auto i:mp)v.pb(i.snd);
		sort(ALL(v));
		reverse(ALL(v));
		//for(auto i:v)cout<<i<<" "; cout<<"\n";
		ll l=1,r=n-1;
		while(l<=r){
			ll m=(l+r)/2;
			//cout<<m<<" "<<(n+m-1)/m<<" "<<n/m<<"\n";
			ll br=0;
			fore(i,0,max(SZ(v),n%m)){
				if(v[i]>(n+m-1)/m){
					
					br++; break;
				}
			}
			fore(i,n%m,SZ(v)){
				if(v[i]>n/m){
					br++; break;
				}
			}
			if(br)r=m-1;
			else l=m+1;
		}
		cout<<r-1<<"\n";
	}
	
	return 0;
}