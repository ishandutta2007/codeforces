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

ll cr(pair<ll,ll> a, pair<ll,ll> b){
	if(a.fst>a.snd)swap(a.fst,a.snd);
	if(b.fst>b.snd)swap(b.fst,b.snd);
	if(b.fst<a.fst)swap(a,b);
	return b.fst<a.snd&&a.snd<b.snd;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		set<ll> st;
		fore(i,0,2*n)st.insert(i);
		vector<pair<ll,ll>> v(k);
		fore(i,0,k)cin>>v[i].fst>>v[i].snd,v[i].fst--,v[i].snd--;
		for(auto i:v)st.erase(i.fst),st.erase(i.snd);
		vector<ll> f;
		for(auto i:st)f.pb(i);
		fore(i,0,SZ(f)/2){
			v.pb({f[i],f[SZ(f)/2+i]});
		}
		ll res=0;
		fore(i,0,SZ(v)){
			fore(j,i+1,SZ(v)){
				res+=cr(v[i],v[j]);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}