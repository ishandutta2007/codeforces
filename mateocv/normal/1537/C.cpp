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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		if(n==2){
			for(auto i:a)cout<<i<<" ";
			cout<<"\n";
		}else{
			pair<ll,ll> mini={1e18,-1};
			fore(i,0,n-1){
				mini=min(mini,{a[i+1]-a[i],i+1});
			}
			fore(i,0,n){
				cout<<a[(mini.snd+i)%n]<<" ";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}