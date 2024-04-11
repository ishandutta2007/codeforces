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

ll c[MAXN],ve[MAXN],tot;

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--; v--;
		ve[u]++;
		ve[v]++;
		c[max(u,v)]++;
	}
	fore(i,0,n){
		tot+=(c[i]==ve[i]);
	}
	ll q; cin>>q;
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll u,v; cin>>u>>v; u--; v--;
			tot-=(c[u]==ve[u]);
			tot-=(c[v]==ve[v]);
			ve[u]++;
			ve[v]++;
			c[max(u,v)]++;
			tot+=(c[u]==ve[u]);
			tot+=(c[v]==ve[v]);
		}else if(ty==2){
			ll u,v; cin>>u>>v; u--; v--;
			tot-=(c[u]==ve[u]);
			tot-=(c[v]==ve[v]);
			ve[u]--;
			ve[v]--;
			c[max(u,v)]--;
			tot+=(c[u]==ve[u]);
			tot+=(c[v]==ve[v]);
		}else{
			cout<<tot<<"\n";
		}
	}
	
	return 0;
}