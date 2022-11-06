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

vector<pair<ll,ll>> fact(ll n){
	vector<pair<ll,ll>> res;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ll c=0;
			while(n%i==0){
				n/=i; c++;
			}
			res.pb({i,c});
		}
	}
	if(n>1)res.pb({n,1});
	return res;
}

ll lpow(ll a, ll b){
	ll res=1;
	fore(i,0,b)res*=a;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pair<ll,ll>> f=fact(n);
		if(SZ(f)==1){
			if(f[0].snd<6){
				cout<<"NO\n"; continue;
			}
			ll p=f[0].fst;
			cout<<"YES\n"<<p<<" "<<p*p<<" "<<n/(p*p*p)<<"\n";
		}else if(SZ(f)==2){
			if(f[0].snd==2&&f[1].snd==2){
				cout<<"YES\n"<<f[0].fst<<" "<<f[1].fst<<" "<<f[0].fst*f[1].fst<<"\n"; continue;
			}
			if(max(f[0].snd,f[1].snd)<3){
				cout<<"NO\n"; continue;
			}
			if(f[0].snd>=3){
				ll p=f[0].fst;
				cout<<"YES\n"<<p<<" "<<lpow(p,f[0].snd-1)<<" "<<n/lpow(p,f[0].snd)<<"\n";
			}else{
				ll p=f[1].fst;
				cout<<"YES\n"<<p<<" "<<lpow(p,f[1].snd-1)<<" "<<n/lpow(p,f[1].snd)<<"\n";
			}
		}else{
			cout<<"YES\n"<<lpow(f[0].fst,f[0].snd)<<" "<<lpow(f[1].fst,f[1].snd)<<" "<<n/(lpow(f[0].fst,f[0].snd)*lpow(f[1].fst,f[1].snd))<<"\n";
		}
	}
	
	return 0;
}