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
		ll n,m; cin>>n>>m;
		vector<ll> a(m);
		fore(i,0,m)cin>>a[i];
		sort(ALL(a));
		vector<ll> v;
		fore(i,0,m)v.pb((a[(i+1)%m]-a[i]+n+n-1)%n);
		sort(ALL(v));
		reverse(ALL(v));
		//for(auto i:v)cout<<i<<" ";
		//cout<<"\n";
		ll res=m;
		fore(i,0,SZ(v)){
			res+=min(v[i],4ll*i+1)-(4ll*i+1==v[i]);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}