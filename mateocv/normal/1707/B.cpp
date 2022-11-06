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

vector<pair<ll,ll>> cont(vector<ll> a){
	vector<pair<ll,ll>> res;
	for(auto i:a){
		if(!SZ(res)||res.back().fst!=i)res.pb({i,1});
		else res.back().snd++;
	}
	return res;
}

ll c[500005];

vector<pair<ll,ll>> trans(vector<pair<ll,ll>> a){
	vector<pair<ll,ll>> res;
	vector<ll> vis={0};
	for(auto i:a)c[0]+=i.snd-1;
	fore(i,0,SZ(a)-1){
		ll d=a[i+1].fst-a[i].fst;
		vis.pb(d);
		assert(d>=0);
		c[d]++;
	}
	sort(ALL(vis));
	vis.erase(unique(ALL(vis)), vis.end());
	for(auto i:vis){
		if(c[i])res.pb({i,c[i]});
		c[i]=0;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		auto ap=cont(a);
		while(SZ(ap)>1){
			ap=trans(ap);
		}
		if(ap.back().snd==1)cout<<ap.back().fst<<"\n";
		else cout<<"0\n";
	}
	
	return 0;
}