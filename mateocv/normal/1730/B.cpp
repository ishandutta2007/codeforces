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
typedef long double ld;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ld maxi=0;
		for(auto i:b)maxi=max(maxi,(ld)i);
		ll it=60;
		ld l=maxi,r=1e9;
		while(it--){
			ld m=(l+r)/2;
			ld mini=2e9,maxi=-1;
			fore(i,0,n){
				maxi=max(maxi,a[i]-m+b[i]);
				mini=min(mini,a[i]+m-b[i]);
			}
			if(maxi<mini)r=m;
			else l=m;
		}
		ld m=(l+r)/2;
		//cout<<m<<"\n";
		ld res=0;
		fore(i,0,n){
			res=max(res,a[i]-m+b[i]);
		}
		cout<<fixed<<setprecision(10)<<res<<"\n";
	}
	
	return 0;
}