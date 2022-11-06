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

pair<ll,ll> minp(pair<ll,ll> p, ll m){
	ll maxi=min(p.fst,m);
	return {maxi,m-maxi};
}

ll minv(pair<ll,ll> p, ll m){
	auto s=minp(p,m);
	return p.fst-s.fst-(p.snd-s.snd);
}

pair<ll,ll> maxp(pair<ll,ll> p, ll m){
	ll maxi=min(p.snd,m);
	return {m-maxi,maxi};
}

ll maxv(pair<ll,ll> p, ll m){
	auto s=maxp(p,m);
	return p.fst-s.fst-(p.snd-s.snd);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<pair<ll,ll>> a(n);
		fore(i,0,n)cin>>a[i].fst>>a[i].snd;
		ll l=0,r=0;
		for(auto i:a){
			l+=minv(i,m);
			r+=maxv(i,m);
		}
		ll val;
		//cout<<l<<" "<<r<<"\n";
		if(l>=0)val=l;
		else if(r<=0)val=r;
		else{
			if(l&1)val=1;
			else val=0;
		}
		cout<<abs(val)<<"\n";
		ll dif=val-l;
		for(auto i:a){
			ll d=maxv(i,m)-minv(i,m);
			ll mini=min(d,dif);
			dif-=mini;
			auto pa=minp(i,m);
			pa.fst-=mini/2;
			pa.snd+=mini/2;
			cout<<pa.fst<<" "<<pa.snd<<"\n";
		}
	}
	
	return 0;
}