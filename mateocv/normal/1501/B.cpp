#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
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
		fore(i,0,n){
			a[i]=min(a[i],i+1);
			if(a[i])b[i-a[i]+1]=max(b[i-a[i]+1],a[i]);
		}
		ll va=0;
		fore(i,0,n){
			va=max(va,b[i]);
			cout<<!!va<<" ";
			va=max(va-1,0ll);
		}
		cout<<"\n";
	}
	
	return 0;
}