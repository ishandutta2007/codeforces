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

vector<ll> oc[MAXN];

pair<ll,ll> nrm(ll x, ll y){
	return {min(x,y),max(x,y)};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		vector<ll> c(n);
		fore(i,0,n)c[i]=b[i]-a[i];
		vector<ll> sump={0};
		fore(i,0,n)sump.pb(sump.back()+c[i]);
		fore(i,0,n+1)oc[i].clear();
		vector<pair<ll,ll>> sr;
		fore(i,0,m){
			ll l,r; cin>>l>>r; l--;
			oc[l].pb(r);
			oc[r].pb(l);
			if(sump[l]==0&&sump[r]==0)sr.pb({l,r});
		}
		set<ll> st;
		fore(i,0,n+1){
			if(sump[i]!=0){
				st.insert(i);
			}
		}
		while(SZ(sr)){
			auto b=sr.back();
			sr.pop_back();
			while(1){
				auto it=st.lower_bound(b.fst);
				if(it==st.end())break;
				auto el=*it;
				if(el>=b.snd)break;
				sump[el]=0;
				for(auto i:oc[el]){
					if(sump[i]==0){
						sr.pb(nrm(el,i));
					}
				}
				st.erase(el);
			}
		}
		ll res=1;
		fore(i,0,n+1){
			if(sump[i]!=0)res=0;
		}
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}