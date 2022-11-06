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
		vector<ll> v;
		fore(i,0,n)v.pb(i);
		ll sum=0;
		vector<pair<ll,ll>> res;
		fore(i,0,n-1){
			ll l=i,r=((i>abs(n-1-i))?0:n-1);
			sum+=(r-l)*(r-l);
			swap(v[l],v[r]);
			res.pb({l,r});
		}
		//vector<ll> u(n);
		//fore(i,0,n)u[v[i]]=i;
		reverse(ALL(res));
		cout<<sum<<"\n";
		for(auto i:v)cout<<i+1<<" ";
		cout<<"\n"<<SZ(res)<<"\n";
		for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	}
	
	return 0;
}