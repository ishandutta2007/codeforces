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
		fore(i,0,n)cin>>a[i],a[i]--;
		ll l=-1;
		fore(i,0,n){
			if(a[i]!=i){
				l=i;
				break;
			}
		}
		if(l!=-1){
			pair<ll,ll> mini={n+1,-1};
			fore(i,l,n)mini=min(mini,{a[i],i});
			reverse(a.begin()+l,a.begin()+mini.snd+1);
		}
		for(auto i:a)cout<<i+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}