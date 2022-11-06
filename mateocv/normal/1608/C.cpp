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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pair<pair<ll,ll>,ll>> v(n);
		fore(i,0,n)cin>>v[i].fst.fst;
		fore(i,0,n)cin>>v[i].fst.snd;
		fore(i,0,n)v[i].snd=i;
		auto vo=v;
		sort(ALL(v));
		//for(auto i:v)cout<<i.fst.fst<<" "<<i.fst.snd<<" "<<i.snd<<"\n";
		set<pair<ll,ll>> st[2];
		for(auto i:v){
			st[0].insert({-i.fst.fst,i.snd});
			st[1].insert({-i.fst.snd,i.snd});
		}
		set<ll> res;
		res.insert(v.back().snd);
		pair<ll,ll> mini=v.back().fst;
		while(1){
			ll op=0;
			if(SZ(st[0])&&mini.fst<=-st[0].begin()->fst){
				auto p=*st[0].begin();
				mini.fst=min(mini.fst,vo[p.snd].fst.fst);
				mini.snd=min(mini.snd,vo[p.snd].fst.snd);
				st[0].erase(p);
				res.insert(p.snd);
				op++;
			}
			if(SZ(st[1])&&mini.snd<=-st[1].begin()->fst){
				auto p=*st[1].begin();
				mini.fst=min(mini.fst,vo[p.snd].fst.fst);
				mini.snd=min(mini.snd,vo[p.snd].fst.snd);
				st[1].erase(p);
				res.insert(p.snd);
				op++;
			}
			if(!op)break;
		}
		fore(i,0,n){
			if(res.count(i))cout<<1;
			else cout<<0;
		}
		cout<<"\n";
	}
	
	return 0;
}