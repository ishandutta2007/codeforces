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
		pair<ll,ll> a[n];
		fore(i,0,n)cin>>a[i].fst>>a[i].snd;
		ll l=a[0].fst,r=a[0].snd;
		fore(i,0,n){
			l=max(l,a[i].fst);
			r=min(r,a[i].snd);
		}
		cout<<max(l-r,0ll)<<"\n";
	}
	
	return 0;
}