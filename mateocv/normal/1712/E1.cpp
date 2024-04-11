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

const int MAXN=200005;

ll v2(ll n){
	return __builtin_ctzll(n);
}

vector<ll> dv[MAXN],dvp[MAXN];

ll cont(ll l, ll r, vector<ll> &v){
	ll posl=lower_bound(ALL(v),l)-v.begin();
	ll posr=lower_bound(ALL(v),r+1)-v.begin();
	return max(posr-posl,0ll);
}

int main(){FIN;
	fore(i,1,MAXN){
		for(ll j=i;j<MAXN;j+=i){
			dv[j].pb(i);
			if(v2(i)==v2(j))dvp[j].pb(2ll*i);
		}
	}
	fore(i,1,MAXN){
		for(auto j:dv[i])dvp[i].pb(j);
		sort(ALL(dvp[i]));
	}
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r;
		ll tot=r-l+1;
		ll res=tot*(tot-1)*(tot-2)/6;
		fore(k,l+2,r+1){
			ll d=cont(l,k-1,dv[k]);
			ll va=0;
			va+=d*(d-1)/2;
			if(k%3==0){
				va+=cont(max(l,k/3+1),2ll*(k/3)-1,dvp[k]);
			}
			//cout<<k<<" "<<va<<"\n";
			res-=va;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}