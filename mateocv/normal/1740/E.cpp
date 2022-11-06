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

const int MAXN=100005;

vector<ll> g[MAXN];

ll h[MAXN],dp[MAXN];

void dfs(ll x){
	for(auto i:g[x]){
		dfs(i);
		h[x]=max(h[x],h[i]);
		dp[x]+=dp[i];
	}
	h[x]++;
	dp[x]=max(dp[x],h[x]);
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-1){
		ll p; cin>>p; p--;
		g[p].pb(i+1);
	}
	dfs(0);
	ll res=dp[0];
	cout<<res<<"\n";
	
	return 0;
}