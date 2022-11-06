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
		vector<ll> a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll res=0;
		fore(i,0,n-1){
			ll d0=abs(a[i+1]-a[i]);
			ll d1=abs(b[i+1]-a[i]);
			ll d2=abs(a[i+1]-b[i]);
			ll d3=abs(b[i+1]-b[i]);
			res+=min(d0+d3,d1+d2);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}