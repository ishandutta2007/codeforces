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

ll conv(vector<ll> v){
	ll res=0;
	for(auto i:v)res=3ll*res+i;
	return res;
}

ll comp(vector<ll> a, vector<ll> b){
	vector<ll> res;
	fore(i,0,SZ(a)){
		res.pb((6-a[i]-b[i])%3);
	}
	return conv(res);
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<vector<ll>> v(n);
	fore(i,0,n){
		v[i].resize(k);
		fore(j,0,k)cin>>v[i][j];
	}
	set<ll> vc;
	fore(i,0,n)vc.insert(conv(v[i]));
	vector<ll> comb;
	fore(i,0,n){
		fore(j,i+1,n){
			comb.pb(comp(v[i],v[j]));
		}
	}
	sort(ALL(comb));
	vector<pair<ll,ll>> val;
	fore(i,0,SZ(comb)){
		if(!SZ(val)||val.back().fst!=comb[i]){
			val.pb({comb[i],1});
		}else val.back().snd++;
	}
	ll res=0;
	for(auto i:val){
		if(vc.count(i.fst))res+=i.snd*(i.snd-1)/2;
	}
	cout<<res<<"\n";
	
	return 0;
}