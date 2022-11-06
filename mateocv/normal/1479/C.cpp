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

struct ed{
	pair<ll,ll> v;
	ll c; 
};

struct gr{
	vector<ed> es;
	ll n;
};

gr cb(ll l, ll r){
	gr res;
	res.n=r-l+2;
	fore(i,1,r-l+2)res.es.pb({{0,i},l});
	fore(i,1,r-l+1)res.es.pb({{i+1,i},1});
	return res;
}

gr addx(gr g, ll x, bool b){
	auto res=g;
	assert(SZ(g.es));
	assert(x>=2);
	ll nv=g.n;
	res.n++;
	res.es.pb({{0,nv},1});
	/*
	fore(i,1,nv){
		if(!b||i!=1)res.es.pb({{nv,i},x-1});
	}
	*/
	for(auto i:g.es){
		if(i.v.fst==0){
			if(!b||i.v.snd!=1)res.es.pb({{nv,i.v.snd},x-1+i.c});
		}
	}
	return res;
}

gr solve(ll l, ll r){
	if(r-l<=6)return cb(l,r);
	ll m=(l+r)/2;
	ll d=r-m;
	auto g=solve(l,m);
	return addx(g,d,l+d==m);
}

int main(){FIN;
	ll l,r; cin>>l>>r;
	auto res=solve(l,r);
	cout<<"YES\n"<<res.n<<" "<<SZ(res.es)<<"\n";
	for(auto i:res.es){
		ll x=-1,y=-1;
		if(i.v.fst==0){
			x=i.v.fst+1;
			cout<<x<<" ";
		}else{
			x=res.n-i.v.fst+1;
			cout<<x<<" ";
		}
		if(i.v.snd==0){
			y=i.v.snd+1;
			cout<<y<<" ";
		}else{
			y=res.n-i.v.snd+1;
			cout<<y<<" ";
		}
		assert(x<y);
		cout<<i.c<<"\n";
	}
	
	return 0;
}