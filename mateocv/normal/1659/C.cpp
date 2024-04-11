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
		ll n,a,b; cin>>n>>a>>b;
		vector<ll> x(n);
		fore(i,0,n)cin>>x[i];
		vector<ll> d={n*x[0]};
		ll s=0;
		fore(i,0,n-1)d.pb((x[i+1]-x[i])*(n-1-i));
		reverse(ALL(d));
		for(auto i:d)s+=i;
		ll res=s*b;
		fore(i,0,n){
			s-=d.back();
			d.pop_back();
			res=min(res,s*b+(a+b)*x[i]);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}