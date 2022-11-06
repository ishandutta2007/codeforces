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

set<ll> st={0};
vector<ll> v;
ll u[1000006];
pair<ll,ll> a[2020],b[2020];
vector<pair<ll,ll>> suf;

bool isin(ll i, ll j){
	return a[i].fst<=b[j].fst&&a[i].snd<=b[j].snd;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	fore(i,0,m)cin>>b[i].fst>>b[i].snd;
	fore(i,0,n){
		fore(j,0,m){
			if(isin(i,j))st.insert(max(b[j].fst-a[i].fst+1,0ll));
		}
	}
	for(auto i:st)v.pb(i);
	sort(ALL(v));
	reverse(ALL(v));
	mset(u,-1);
	fore(i,0,SZ(v)){
		u[v[i]]=i;
	}
	suf.pb({0,0});
	suf.pb({SZ(v)+1,0});
	fore(i,0,n){
		fore(j,0,m){
			if(isin(i,j)){
				ll d=max(b[j].fst-a[i].fst+1,0ll);
				ll ud=u[d]+1;
				suf.pb({ud,max(b[j].snd-a[i].snd+1,0ll)});
			}
		}
	}
	ll res=9e18;
	ll maxi=0;
	sort(ALL(suf));
	fore(i,0,SZ(suf)-1){
		maxi=max(maxi,suf[i].snd);
		if(suf[i].fst<suf[i+1].fst){
			res=min(res,v[suf[i].fst]+maxi);
		}
	}
	cout<<res<<"\n";
	
	return 0;
}