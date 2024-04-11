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

const int MAXN=5050;

vector<ll> a;

ll dp[MAXN][MAXN];

ll INF=1e18;

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==SZ(a)){
		if(y==MAXN/2)res=0;
		else res=INF;
		return res;
	}
	if(a[x]==0){
		res=f(x+1,y)+abs(y-MAXN/2);
		if(y)res=min(res,f(x+1,y-1)+abs(y-1-MAXN/2));
	}else{
		res=f(x+1,y+1)+abs(y+1-MAXN/2);
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	a.resize(n);
	fore(i,0,n)cin>>a[i];
	mset(dp,-1);
	cout<<f(0,MAXN/2)<<"\n";
	
	return 0;
}