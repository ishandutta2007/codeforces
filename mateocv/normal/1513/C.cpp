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

vector<ll> cd(ll n){
	vector<ll> v(10);
	while(n){
		v[n%10]++;
		n/=10;
	}
	return v;
}

ll MOD=1000000007;

ll dp[200005][11];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==0)return res=1;
	if(y!=9)res=f(x-1,y+1);
	else res=(f(x-1,0)+f(x-1,1))%MOD;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	mset(dp,-1);
	while(t--){
		ll n,m; cin>>n>>m;
		auto v=cd(n);
		ll res=0;
		fore(i,0,10)res=(res+f(m,i)*v[i])%MOD;
		cout<<res<<"\n";
	}
	
	return 0;
}