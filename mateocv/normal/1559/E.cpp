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

const ll MOD=998244353;

short mu[MAXN] = {0,1};
void mobius(){
	fore(i,1,MAXN)if(mu[i])for(int j=i+i;j<MAXN;j+=i)mu[j]-=mu[i];
}

ll dp[52][MAXN];

ll sump[52][MAXN];

ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

ll sub(ll x, ll y){
	x-=y;
	if(x<0)x+=MOD;
	return x;
}

ll solve(vector<pair<ll,ll>> b, ll m){
	for(auto i:b){
		if(i.fst>i.snd)return 0;
	}
	fore(i,0,m+1){
		fore(j,0,SZ(b)+1){
			dp[j][i]=0;
			sump[j][i]=0;
		}
	}
	dp[SZ(b)][0]=1;
	fore(j,0,m+1){
		if(j)sump[SZ(b)][j]=sump[SZ(b)][j-1];
		sump[SZ(b)][j]=add(sump[SZ(b)][j],dp[SZ(b)][j]);
	}
	for(ll i=SZ(b)-1;i>=0;i--){
		fore(j,0,m+1){
			dp[i][j]=0;
			if(j-b[i].fst>=0)dp[i][j]=sump[i+1][j-b[i].fst];
			if(j-b[i].snd-1>=0)dp[i][j]=sub(dp[i][j],sump[i+1][j-b[i].snd-1]);
			if(j)sump[i][j]=sump[i][j-1];
			sump[i][j]=add(sump[i][j],dp[i][j]);
		}
	}
	ll res=0;
	fore(i,0,m+1){
		res=add(res,dp[0][i]);
	}
	return res;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<pair<ll,ll>> a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	vector<ll> c(m+1);
	mobius();
	fore(i,1,m+1){
		vector<pair<ll,ll>> b;
		for(auto j:a){
			b.pb({(j.fst+i-1)/i,j.snd/i});
		}
		c[i]=solve(b,m/i);
	}
	ll res=0;
	fore(i,1,m+1){
		res=(res+MOD+mu[i]*c[i])%MOD;
	}
	cout<<res<<"\n";
	
	return 0;
}