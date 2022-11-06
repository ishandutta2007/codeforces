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

const int MAXN=200005;

vector<ll> g[MAXN];

vector<ll> l,r;

pair<ll,ll> solve(ll x){
	pair<ll,ll> res={0,0};
	for(auto i:g[x]){
		auto s=solve(i);
		res.fst+=s.fst;
		res.snd+=s.snd;
	}
	if(res.snd<l[x]){
		res.fst++;
		res.snd=r[x];
	}else if(res.snd>r[x]){
		res.snd=r[x];
	}
	//cout<<x<<" "<<res.fst<<" "<<res.snd<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> p(n,-1);
		fore(i,1,n)cin>>p[i],p[i]--;
		fore(i,0,n)g[i].clear();
		fore(i,1,n)g[p[i]].pb(i);
		l.clear(); l.resize(n);
		r.clear(); r.resize(n);
		fore(i,0,n)cin>>l[i]>>r[i];
		auto res=solve(0);
		cout<<res.fst<<"\n";
	}
	
	return 0;
}