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

const int MAXN = 200005;

vector<ll> g[MAXN];

ll a[MAXN],n;

ll s[MAXN],c[MAXN];

void dfs(ll v){
	for(auto i:g[v])dfs(i);
	s[v]=a[v];
	if(SZ(g[v])==0)c[v]=1;
	for(auto i:g[v])s[v]+=s[i],c[v]+=c[i];
}

int main(){FIN;
	cin>>n;
	fore(i,0,n-1){
		ll p; cin>>p; p--;
		g[p].pb(i+1);
	}
	fore(i,0,n)cin>>a[i];
	dfs(0);
	ll res=0;
	fore(i,0,n){
		res=max(res,(s[i]+c[i]-1)/c[i]);
	}
	cout<<res<<"\n";
	return 0;
}