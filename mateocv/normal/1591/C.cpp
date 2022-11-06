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

pair<ll,ll> solve(vector<ll> v, ll k){
	if(SZ(v)==0)return {0,0};
	fore(i,0,SZ(v))v[i]=abs(v[i]);
	sort(ALL(v));
	reverse(ALL(v));
	pair<ll,ll> res={0,0};
	for(ll i=0;i<SZ(v);i+=k)res.fst+=v[i];
	res.fst*=2;
	res.snd=res.fst-v[0];
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> v[2];
		fore(i,0,n){
			if(a[i]>0)v[0].pb(a[i]);
			if(a[i]<0)v[1].pb(a[i]);
		}
		auto s0=solve(v[0],k);
		auto s1=solve(v[1],k);
		cout<<min(s0.fst+s1.snd,s0.snd+s1.fst)<<"\n";
	}
	
	return 0;
}