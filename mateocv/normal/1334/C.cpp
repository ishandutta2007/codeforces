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
		fore(i,0,n){
			a[i].snd=min(a[i].snd,a[(i+1)%n].fst);
		}
		ll mini=1e13;
		ll res=0;
		fore(i,0,n){
			res+=a[i].fst-a[i].snd;
			mini=min(mini,a[i].snd);
		}
		cout<<res+mini<<"\n";
	}
	
	
	return 0;
}