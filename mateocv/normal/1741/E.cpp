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

ll n;

vector<ll> g[200005];

ll dp[200005];

ll f(ll x){
	ll &res=dp[x];
	if(res>=0)return res;
	if(x==n)return res=1;
	res=0;
	for(auto i:g[x])res=max(res,f(i));
	//cout<<x<<" -> "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n+1)g[i].clear();
		fore(i,0,n){
			if(i+a[i]+1<=n)g[i].pb(i+a[i]+1);
			if(i-a[i]>=0)g[i-a[i]].pb(i+1);
		}
		/*
		fore(i,0,n+1){
			cout<<i<<": ";
			for(auto j:g[i])cout<<j<<" ";
			cout<<"\n";
		}
		*/
		fore(i,0,n+1)dp[i]=-1;
		cout<<(f(0)?"YES\n":"NO\n");
	}
	
	return 0;
}