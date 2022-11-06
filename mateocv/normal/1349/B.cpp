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
		ll n,k; cin>>n>>k;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll hay=0;
		if(n==1){
			if(a[0]==k)cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		vector<ll> v;
		fore(i,0,n){
			if(a[i]==k){
				hay++;
			}
			if(a[i]>=k)v.pb(i);
		}
		ll dos=0;
		fore(i,0,SZ(v)-1){
			if(v[i+1]-v[i]<=2)dos++;
		}
		if(dos&&hay){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	
	return 0;
}