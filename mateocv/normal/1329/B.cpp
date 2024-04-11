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

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

ll dp[35][35][2];

ll MOD,d;

ll f(ll x, ll y, ll b){
	ll &r=dp[x][y][b];
	if(r>=0)return r;
	if(y==0){
		return r=(x==0);
	}
	if(x==0)return r=1;
	r=0;
	fore(i,0,y){
		r+=f(x-1,i,0)*((1ll<<(i))+(b&&i==y-1)*(d+1-(1ll<<(i+1))));
		r%=MOD;
	}
	return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		mset(dp,-1);
		ll m; cin>>d>>m;
		MOD=m;
		ll res=0;
		ll l=0;
		fore(j,0,31){
			if((1ll<<j)>d){
				l=j; break;
			}
		}
		fore(j,1,l+1){
			res=(res+f(j,l,1))%m;
			//cout<<res<<"\n";
		}
		cout<<res<<"\n";
	}
	
	return 0;
}