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
		ll n,k,d; cin>>n>>k>>d;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		map<ll,ll> m;
		fore(i,0,d){
			m[a[i]]++;
		}
		ll res=SZ(m);
		fore(i,d,n){
			m[a[i-d]]--;
			if(m[a[i-d]]==0)m.erase(a[i-d]);
			m[a[i]]++;
			res=min(res,SZ(m));
		}
		cout<<res<<"\n";
	}
	
	return 0;
}