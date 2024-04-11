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

const ll MOD=1000000007;

const ll d2=500000004;

const int MAXN=2020;

ll dp[MAXN][MAXN];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==y)return res=x;
	if(y==0)return res=0;
	res=(f(x-1,y)+f(x-1,y-1))%MOD;
	res=res*d2%MOD;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	mset(dp,-1);
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		ll res=f(n,m)*k%MOD;
		cout<<res<<"\n";
	}
	
	return 0;
}