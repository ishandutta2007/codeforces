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
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> res;
		ll maxi=0;
		for(auto i:a)maxi=max(maxi,i);
		fore(i,0,n){
			if(a[i]==maxi){
				a[i]=-1;
				break;
			}
		}
		res.pb(maxi);
		ll va=maxi;
		while(1){
			pair<ll,ll> maxb={0,-1};
			fore(i,0,n){
				if(a[i]!=-1){
					maxb=max(maxb,{(a[i]|va)^va,i});
				}
			}
			if(maxb.fst==0)break;
			res.pb(a[maxb.snd]);
			a[maxb.snd]=-1;
			va=(va|maxb.fst);
		}
		fore(i,0,n){
			if(a[i]!=-1)res.pb(a[i]);
		}
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}