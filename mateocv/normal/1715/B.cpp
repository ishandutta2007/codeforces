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
		ll n,k,b,s; cin>>n>>k>>b>>s;
		ll va=s-b*k;
		if(!(0<=va&&va<=n*(k-1)))cout<<"-1\n";
		else{
			vector<ll> res(n);
			res[0]=b*k;
			fore(i,0,n){
				ll mini=min(va,k-1);
				va-=mini;
				res[i]+=mini;
			}
			for(auto i:res)cout<<i<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}