#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll t[300005];
vector<ll> g[300005];
ll dp[300005];
ll h=0;

ll f(ll v){
	ll &r=dp[v];
	if(r>=0)return r;
	if(SZ(g[v])==0){
		h++; r=0; return r;
	}
	if(t[v]==0){
		r=0;
		for(auto i:g[v]){
			r+=f(i);
		}
		r+=SZ(g[v])-1;
		return r;
	}
	if(t[v]==1){
		r=f(g[v][0]);
		for(auto i:g[v]){
			r=min(f(i),r);
		}
		return r;
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>t[i];
	ll p;
	fore(i,1,n){
		cin>>p; p--;
		g[p].pb(i);
	}
	mset(dp,-1);
	ll res=f(0);
	cout<<h-res;
	return 0;
}