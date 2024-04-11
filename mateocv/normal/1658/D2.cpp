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

vector<ll> gen(ll l, ll r, ll x){
	vector<ll> res;
	fore(i,l,r+1)res.pb(i^x);
	sort(ALL(res));
	return res;
}

ll solve(vector<ll> a, ll l, ll r){
	if(SZ(a)&1){
		ll x=0,xa=0;
		fore(i,l,r+1)x^=i;
		fore(i,0,SZ(a))xa^=a[i];
		return x^xa;
	}
	sort(ALL(a));
	ll br=0;
	fore(i,0,SZ(a)/2)br+=((a[2*i]^1)!=a[2*i+1]);
	if(!br){
		vector<ll> b;
		fore(i,0,SZ(a)/2)b.pb(a[2*i]/2);
		return 2ll*solve(b,l/2,r/2);
	}else{
		set<ll> st;
		for(auto i:a)st.insert(i);
		vector<ll> b;
		for(auto i:a){
			if(!st.count(i^1))b.pb(i);
		}
		assert(SZ(b)<=2);
		for(auto i:b){
			ll val=(i^l);
			if(gen(l,r,val)==a)return val;
		}
	}
	return -1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r;
		ll n=r-l+1;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		cout<<solve(a,l,r)<<"\n";
	}
	
	return 0;
}