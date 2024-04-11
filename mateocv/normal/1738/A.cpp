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
		vector<ll> v[2];
		fore(i,0,n)v[a[i]].pb(b[i]);
		fore(k,0,2)sort(ALL(v[k]));
		fore(k,0,2)reverse(ALL(v[k]));
		ll res=0;
		fore(k,0,2)for(auto i:v[k])res+=i;
		fore(k,0,2){
			fore(j,0,min(SZ(v[k]),SZ(v[k^1])))res+=v[k][j];
		}
		ll mini=1e10;
		if(SZ(v[0])==SZ(v[1])){
			if(SZ(v[0]))mini=min(mini,v[0].back());
			if(SZ(v[1]))mini=min(mini,v[1].back());
			res-=mini;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}