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
		fore(i,0,n){
			cout<<*lower_bound(ALL(b),a[i])-a[i]<<" ";
		}
		cout<<"\n";
		vector<ll> vp;
		fore(i,1,n){
			if(a[i]>b[i-1])vp.pb(i);
		}
		vp.pb(n);
		fore(i,0,n){
			auto pos=*lower_bound(ALL(vp),i+1);
			cout<<b[pos-1]-a[i]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}