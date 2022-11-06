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
		if(n==4&&k==3){
			cout<<"-1\n";
			continue;
		}
		vector<pair<ll,ll>> res;
		vector<ll> vis(n);
		vector<ll> u;
		fore(i,0,16){
			if((1ll<<i)&k)u.pb((1ll<<i));
		}
		if(SZ(u)>1){
			fore(i,0,SZ(u)){
				res.pb({u[i],n-1-u[(i+1)%SZ(u)]});
				vis[res.back().fst]++;
				vis[res.back().snd]++;
			}
		}else if(SZ(u)==1){
			ll ot=n-1;
			res.pb({u[0],ot});
			vis[res.back().fst]++;
			vis[res.back().snd]++;
			res.pb({n-1-u[0],n-1-ot});
			vis[res.back().fst]++;
			vis[res.back().snd]++;
		}
		fore(i,0,n-1){
			if(!vis[i]){
				res.pb({i,n-1-i});
				vis[res.back().fst]++;
				vis[res.back().snd]++;
			}
		}
		ll x=0;
		for(auto i:res)x+=(i.fst&i.snd);
		assert(x==k);
		for(auto i:res)cout<<i.fst<<" "<<i.snd<<"\n";
	}
	
	return 0;
}