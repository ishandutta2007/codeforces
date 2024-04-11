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

vector<pair<ll,ll>> fact(ll x){
	vector<pair<ll,ll>> res;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){ll cuenta=0;
			while(x%i==0){
				cuenta++; x/=i;	
			}
			pair<ll,ll> pr;
			pr.fst=i; pr.snd=cuenta;
			res.pb(pr);
		}
	}
	if(x>1){
	pair<ll,ll> pr;
	pr.fst=x; pr.snd=1;
	res.pb(pr);}
	return res;
}

ll cant(ll n, ll p){
	ll res=0;
	while(n%p==0){
		res++;
		n/=p;
	}
	return res;
}

ll pot(ll b, ll e){
	ll res=1;
	fore(i,0,e)res*=b;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll p,q; cin>>p>>q;
		auto f=fact(q);
		if(p%q!=0){
			cout<<p<<"\n";
			continue;
		}
		ll res=1;
		fore(i,0,SZ(f)){
			fore(j,1,cant(p,f[i].fst)+1){
				ll va=p/pot(f[i].fst,j);
				if(va%q!=0){
					res=max(res,va);
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}