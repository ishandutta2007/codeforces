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

vector<pair<ll,ll>> v;

set<ll> st;
map<ll,ll> comp;

const int MAXN=400005;

pair<ll,ll> NEUT={9e18,-1};

pair<ll,ll> f[MAXN],s[MAXN];
pair<ll,ll> minif[MAXN],minis[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		v.clear();
		st.clear();
		comp.clear();
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			v.pb({x,y});
			st.insert(x);
			st.insert(y);
		}
		ll va=0;
		for(auto i:st){
			comp[i]=va++;
		}
		fore(i,0,SZ(v)){
			v[i].fst=comp[v[i].fst];
			v[i].snd=comp[v[i].snd];
		}
		fore(i,0,va){
			f[i]=NEUT;
			s[i]=NEUT;
		}
		fore(i,0,SZ(v)){
			f[v[i].fst]=min(f[v[i].fst],{v[i].snd,i});
			s[v[i].snd]=min(s[v[i].snd],{v[i].fst,i});
		}
		minif[0]=NEUT;
		fore(i,0,va){
			minif[i+1]=min(minif[i],f[i]);
		}
		minis[0]=NEUT;
		fore(i,0,va){
			minis[i+1]=min(minis[i],s[i]);
		}
		fore(i,0,n){
			ll res=-2;
			auto q=minif[v[i].fst];
			if(q.fst<v[i].snd)res=q.snd;
			q=minis[v[i].fst];
			if(q.fst<v[i].snd)res=q.snd;
			cout<<res+1<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}