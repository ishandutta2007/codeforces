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
		if(n%x){
			cout<<"-1\n";
			continue;
		}
		vector<ll> v={x};
		while(v.back()!=n){
			auto b=v.back();
			ll nb=2ll*b;
			while(n%nb)nb+=b;
			v.pb(nb);
		}
		vector<ll> res(n,-1);
		res.back()=1;
		res[0]=x;
		fore(i,0,SZ(v)-1)res[v[i]-1]=v[i+1];
		fore(i,0,n){
			if(res[i]==-1)res[i]=i+1;
		}
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}