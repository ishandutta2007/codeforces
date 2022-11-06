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

map<ll,ll> mp;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		mp.clear();
		fore(i,0,n){
			mp[a[i]]++;
		}
		ll mini=-1;
		for(auto i:mp){
			if(i.snd==1){
				mini=i.fst;
				break;
			}
		}
		if(mini==-1){
			cout<<"-1\n";
		}else{
			fore(i,0,n){
				if(a[i]==mini){
					cout<<i+1<<"\n"; break;
				}
			}
		}
	}
	
	return 0;
}