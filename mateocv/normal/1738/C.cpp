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

ll dp[110][110][3][3];

ll f(ll x, ll y, ll s, ll p){
	ll &res=dp[x][y][s][p];
	if(res>=0)return res;
	if(x+y==0)return res=(s==p);
	res=1;
	if(x)res=min(res,f(x-1,y,s,p^1));
	if(y)res=min(res,f(x,y-1,s^(p==0),p^1));
	res^=1;
	return res;
}

int main(){FIN;
	mset(dp,-1);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll c[2]={0,0};
		fore(i,0,n){
			ll x; cin>>x;
			c[(x&1)]++;
		}
		if(f(c[0],c[1],0,0))cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	
	return 0;
}