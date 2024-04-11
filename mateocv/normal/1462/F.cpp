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
typedef int ll;

vector<pair<ll,ll>> v;

map<ll,ll> mp;
set<ll> st;

ll cm(){
	st.clear();
	mp.clear();
	for(auto i:v){
		st.insert(i.fst);
		st.insert(i.snd);
	}
	ll va=0;
	for(auto i:st)mp[i]=va++;
	fore(i,0,SZ(v)){
		v[i].fst=mp[v[i].fst];
		v[i].snd=mp[v[i].snd];
	}
	return va;
}

ll cl[400005],cr[400005];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		v.clear();
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			v.pb({x,y});
		}
		cm();
		fore(i,0,2*n+1)cl[i]=0,cr[i]=0;
		for(auto i:v){
			cl[i.fst+1]++;
			cr[i.snd+1]++;
		}
		fore(i,0,2*n+1){
			cl[i+1]=cl[i]+cl[i+1];
			cr[i+1]=cr[i]+cr[i+1];
		}
		ll res=n-1;
		fore(i,0,n){
			res=min(res,cr[v[i].fst]+cl[2*n]-cl[v[i].snd+1]);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}