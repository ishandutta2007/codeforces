#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> g[100005];

int main(){FIN;
	ll n; cin>>n;
	ll u,v;
	fore(i,0,n-1){
		cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(i,0,n){
		if(SZ(g[i])==2){
			cout<<"NO"; return 0;
		}
	}
	cout<<"YES";
	return 0;
}