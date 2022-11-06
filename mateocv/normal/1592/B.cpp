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
		ll n,x; cin>>n>>x;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> v,f(n);
		fore(i,0,n){
			f[i]=1;
			if(i-x>=0||i+x<n)f[i]=0;
		}
		fore(i,0,n){
			if(!f[i])v.pb(a[i]);
		}
		sort(ALL(v));
		reverse(ALL(v));
		vector<ll> res;
		fore(i,0,n){
			if(f[i])res.pb(a[i]);
			else res.pb(v.back()),v.pop_back();
		}
		sort(ALL(a));
		if(a==res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}