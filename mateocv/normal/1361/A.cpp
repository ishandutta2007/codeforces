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

vector<ll> g[500005];

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll t[n];
	fore(i,0,n)cin>>t[i],t[i]--;
	fore(i,0,n){
		for(auto j:g[i]){
			if(t[i]==t[j]){
				cout<<-1;
				return 0;
			}
		}
	}
	pair<ll,ll> p[n];
	fore(i,0,n)p[i]={t[i],i};
	sort(p,p+n);
	ll vis[n];
	mset(vis,0);
	fore(i,0,n){
		set<ll> st;
		for(auto j:g[p[i].snd])if(vis[j])st.insert(t[j]);
		ll mex=-1;
		fore(i,0,SZ(st)+1){
			if(!st.count(i)){
				mex=i; break;
			}
		}
		if(mex!=p[i].fst){
			cout<<-1;
			return 0;
		}
		vis[p[i].snd]++;
	}
	fore(i,0,n)cout<<p[i].snd+1<<" ";
	
	return 0;
}