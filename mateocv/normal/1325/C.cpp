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

vector<ll> g[200005];

int main(){FIN;
	ll n; cin>>n;
	map<pair<ll,ll>,ll> mp;
	ll u,v;
	fore(i,0,n-1){
		cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
		mp[{min(u,v),max(u,v)}]=i;
	}
	ll res[n-1];
	mset(res,-1);
	ll va=0;
	fore(i,0,n){
		if(SZ(g[i])==1){
			if(res[mp[{min(i,g[i][0]),max(i,g[i][0])}]]==-1)res[mp[{min(i,g[i][0]),max(i,g[i][0])}]]=va++;
		}
	}
	//fore(i,0,n-1)cout<<res[i]<<"\n";
	fore(i,0,n-1){
		if(res[i]==-1)res[i]=va++;
	}
	fore(i,0,n-1)cout<<res[i]<<"\n";
	return 0;
}