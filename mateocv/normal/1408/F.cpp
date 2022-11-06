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

vector<pair<ll,ll>> solve(ll l, ll r){
	if(r-l==1){
		return {};
	}
	vector<pair<ll,ll>> res;
	ll mid=(l+r)/2;
	auto v0=solve(l,mid);
	for(auto i:v0)res.pb(i);
	auto v1=solve(mid,r);
	for(auto i:v1)res.pb(i);
	fore(i,0,mid-l){
		res.pb({l+i,mid+i});
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	ll pot=1;
	while(2*pot<=n){
		pot*=2;
	}
	vector<pair<ll,ll>> res;
	auto v0=solve(0,pot);
	for(auto i:v0)res.pb(i);
	auto v1=solve(n-pot,n);
	for(auto i:v1)res.pb(i);
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	return 0;
}