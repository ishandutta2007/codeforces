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

ll MOD=998244353;

ll fact[300005];

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll comb(ll n, ll k){
	if(k>n)return 0;
	return fact[n]*fpow(fact[k]*fact[n-k]%MOD,MOD-2)%MOD;
}

vector<pair<pair<ll,ll>,ll>> v;

set<ll> st,ne;

int main(){FIN;
	ll n,k; cin>>n>>k;
	fact[0]=1;
	fore(i,1,300005)fact[i]=fact[i-1]*i%MOD;
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		v.pb({{x,1},i});
		v.pb({{y+1,-1},i});
	}
	sort(ALL(v));
	//for(auto i:v)cout<<i.fst.fst<<" "<<i.fst.snd<<" "<<i.snd<<"\n";
	ll res=0,va=0;
	fore(i,0,SZ(v)){
		va+=v[i].fst.snd;
		if(v[i].fst.snd==1)ne.insert(v[i].snd);
		if(v[i].fst.snd==-1)st.erase(v[i].snd);
		if(v[i].fst.snd==-1)ne.erase(v[i].snd);
		if(i==SZ(v)-1||v[i].fst<v[i+1].fst){
			res=(res+comb(va,k))%MOD;
			res=(res-comb(SZ(st),k)+MOD)%MOD;
			for(auto i:ne)st.insert(i);
			ne.clear();
		}
	}
	cout<<res<<"\n";
	return 0;
}