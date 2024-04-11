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
	vector<ll> v={1};
	while(3ll*v.back()<1000000000)v.pb(3ll*v.back());
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n<=SZ(v)){
			cout<<"YES\n";
			fore(i,0,n)cout<<v[i]<<" ";
			cout<<"\n";
		}else cout<<"NO\n";
	}
	
	return 0;
}