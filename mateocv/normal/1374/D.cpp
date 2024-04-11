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
		map<ll,ll> mp;
		fore(i,0,n){
			mp[(k-a[i]%k)%k]++;
		}
		ll res=-1;
		for(auto i:mp){
			if(i.fst==0)continue;
			res=max(res,k*(i.snd-1)+i.fst);
		}
		cout<<res+1<<"\n";
	}
	
	return 0;
}