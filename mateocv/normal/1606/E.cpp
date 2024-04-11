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

const int MAXN=505;

const ll MOD=998244353;

ll comb[MAXN][MAXN];

ll pot[MAXN][MAXN];

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll dp[MAXN][MAXN];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==0||y==0)return res=0;
	if(x==1)return res=y;
	res=0;
	fore(i,0,x){
		ll val=comb[x][i]*pot[min(y,x-1)][i]%MOD;
		res=(res+val*f(x-i,y-min(y,x-1)))%MOD;
	}
	//cout<<x<<" "<<y<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll n,x; cin>>n>>x;
	fore(i,0,MAXN){
		fore(j,0,i+1){
			if(j==0||j==i)comb[i][j]=1;
			else comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
			//cout<<i<<" "<<j<<" "<<comb[i][j]<<"\n";
		}
	}
	fore(i,0,MAXN){
		fore(j,0,MAXN){
			pot[i][j]=fpow(i,j);
		}
	}
	mset(dp,-1);
	ll res=(pot[x][n]+MOD-f(n,x))%MOD;
	cout<<res<<"\n";
	
	return 0;
}