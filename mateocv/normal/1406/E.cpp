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

ll tot=0;

ll ask(ll t, ll k){
	tot++;
	assert(tot<=10000);
	cout<<char('A'+t)<<" "<<k<<endl;
	if(t==2)exit(0);
	ll resp; cin>>resp;
	return resp;
}

ll esp(ll n){
	ll m=1;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			m=i;
			break;
		}
	}
	if(m==1)m=n;
	while(n%m==0)n/=m;
	return (n==1)*m;
}

vector<pair<ll,ll>> pot,va;

vector<vector<pair<ll,ll>>> v;

set<ll> ban;

int main(){FIN;
	ll n; cin>>n;
	fore(i,2,n+1){
		ll e=esp(i);
		if(e)pot.pb({i,e});
	}
	for(auto i:pot){
		va.pb(i);
		if(SZ(va)==50){
			reverse(ALL(va));
			v.pb(va);
			va.clear();
		}
	}
	if(SZ(va)){
		reverse(ALL(va));
		v.pb(va);
		va.clear();
	}
	reverse(ALL(v));
	ll res=1;
	ll cant=n;
	fore(i,0,SZ(v)){
		for(auto j:v[i]){
			if(ban.count(j.fst))continue;
			cant-=ask(1,j.fst);
		}
		ll a=ask(0,1);
		if(a!=cant){
			cant=a;
			for(auto j:v[i]){
				if(ban.count(j.fst))continue;
				if(ask(0,j.fst)==1){
					res*=j.fst;
					ll vaj=j.fst/j.snd;
					while(vaj>1){
						ban.insert(vaj);
						vaj/=j.snd;
					}
				}
			}
		}
	}
	ask(2,res);
	return 0;
}