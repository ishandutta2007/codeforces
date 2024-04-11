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

ll MOD=1000000007;

ll dp[2000006][2];

ll solve(ll n, ll b){
	ll &r=dp[n][b];
	if(r>=0)return r;
	if(n<=2)return r=0;
	if(n==3)return r=4;
	if(b==1){
		r=(solve(n-1,0)+2*solve(n-2,0))%MOD;
	}else{
		if(n%3==0)r=(4+solve(n-1,1)+2*solve(n-2,1))%MOD;
		else r=(solve(n-1,0)+2*solve(n-2,0))%MOD;
	}
	return r;
}

int main(){FIN;
	ll t; cin>>t;
	mset(dp,-1);
	while(t--){
		ll n; cin>>n;
		cout<<solve(n,0)<<"\n";
	}
	
	return 0;
}