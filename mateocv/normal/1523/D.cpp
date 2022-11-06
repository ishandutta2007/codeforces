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

ll stob(string s){
	ll res=0;
	fore(i,0,SZ(s)){
		if(s[i]=='1')res|=(1ll<<i);
	}
	return res;
}

string btos(ll n, ll k){
	string res;
	fore(i,0,k){
		if((1ll<<i)&n)res+='1';
		else res+='0';
	}
	return res;
}

vector<ll> gen(ll n){
	vector<ll> res={0};
	for(ll s=n;s;s=(s-1)&n){
		res.pb(s);
	}
	return res;
}

vector<ll> a;

ll solve(ll val){
	map<ll,ll> mp;
	auto g=gen(val);
	for(auto i:g)mp[i]=0;
	sort(ALL(g));
	reverse(ALL(g));
	fore(i,0,SZ(a)){
		mp[val&a[i]]++;
	}
	ll m=__builtin_popcountll(val);
	ll cant[1ll<<m];
	ll cantr[1ll<<m];
	mset(cant,0);
	mset(cantr,0);
	vector<ll> v;
	ll van=0;
	for(auto i:mp){
		cant[van]=i.snd;
		v.pb(i.fst);
		van++;
	}
	fore(i,0,(1ll<<m)){
		auto gg=gen(i);
		for(auto j:gg){
			cantr[j]+=cant[i];
		}
	}
	//cout<<val<<"\n";
	//for(auto i:mp)cout<<i.fst<<" "<<i.snd<<"\n";
	ll res=0;
	fore(i,0,(1ll<<m)){
		if(cantr[i]>=(SZ(a)+1)/2){
			ll va=v[i];
			if(__builtin_popcountll(va)>__builtin_popcountll(res))res=va;
		}
	}
	return res;
}

int main(){FIN;
	ll n,m,p; cin>>n>>m>>p;
	srand(ll(&n));
	a.resize(n);
	fore(i,0,n){
		string s; cin>>s;
		a[i]=stob(s);
	}
	ll res=0;
	ll it=20;
	while(it--){
		ll r=abs((rand()<<15)^rand())%n;
		ll va=solve(a[r]);
		if(__builtin_popcountll(va)>__builtin_popcountll(res))res=va;
	}
	cout<<btos(res,m)<<"\n";
	
	return 0;
}