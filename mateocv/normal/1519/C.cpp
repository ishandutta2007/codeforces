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

vector<ll> g[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n){
			ll x; cin>>x;
			g[a[i]].pb(x);
		}
		fore(i,0,n){
			sort(ALL(g[i]));
			reverse(ALL(g[i]));
		}
		vector<ll> res(n);
		fore(i,0,n){
			vector<ll> sump={0};
			for(auto j:g[i])sump.pb(j+sump.back());
			fore(j,1,SZ(g[i])+1){
				res[j-1]+=sump[(SZ(g[i])/j)*j];
			}
		}
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}