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

const ll MOD=998244353;

ll sq=404;

vector<pair<ll,pair<ll,ll>>> gen(ll x){
	vector<pair<ll,pair<ll,ll>>> res;
	vector<ll> v;
	fore(i,0,min(sq,x))v.pb(i);
	
	for(ll i=min(sq,x)-1;i>=0;i--){
		v.pb(x/(i+1)-1);
		v.pb(x/(i+1));
		v.pb(x/(i+1)+1);
	}
	
	ll ul=-1;
	for(auto i:v){
		if(i<=ul||i>=x)continue;
		pair<ll,pair<ll,ll>> p={i,{(x+i)/(i+1),x/(i+1)}};
		if(!SZ(res)||res.back().snd.fst!=p.snd.fst)res.pb(p);
		ul=i;
	}
	//cout<<x<<":\n";
	//for(auto i:res)cout<<i.fst<<" "<<i.snd.fst<<" "<<i.snd.snd<<"\n";
	//cout<<"endg"<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		reverse(ALL(a));
		ll res=0,resu=0;
		vector<pair<ll,ll>> vp;
		for(auto i:a){
			//res=(res+resu)%MOD;
			auto g=gen(i);
			ll ul=0;
			vector<pair<ll,ll>> nvp={{i,1}};
			//cout<<"nl"<<"\n";
			for(auto j:vp){
				//cout<<j.fst<<" "<<j.snd<<" ";
				while(g[ul].snd.fst>j.fst)ul++;
				//cout<<ul<<"\n";
				pair<ll,ll> p={g[ul].snd.snd,j.snd};
				if(nvp.back().fst!=p.fst)nvp.pb(p);
				else nvp[SZ(nvp)-1].snd+=p.snd;
				resu=(resu+g[ul].fst*j.snd)%MOD;
			}
			res=(res+resu)%MOD;
			vp=nvp;
			//cout<<res<<"\n";
		}
		cout<<res<<"\n";
	}
	
	return 0;
}