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
		ll n,h; cin>>n>>h;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		ll val1=2ll*((h+a[n-1]+a[n-2]-1)/(a[n-1]+a[n-2]));
		ll val2=2ll*((h+a[n-2]-1)/(a[n-1]+a[n-2]))+1;
		//cout<<val1<<" "<<val2<<"\n";
		ll res=min(val1,val2);
		cout<<res<<"\n";
	}
	
	return 0;
}