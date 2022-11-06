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

const int MAXN=300005;
ll n,q; 
ll a[MAXN];

ll dp[MAXN][2];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return dp[x][y];
	if(x==n){
		return res=0;
	}
	res=0;
	if(!y){
		res=max(f(x+1,y),f(x+1,y^1)+a[x]);
	}else{
		res=max(f(x+1,y),f(x+1,y^1)-a[x]);
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>q;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n+1)dp[i][0]=-1,dp[i][1]=-1;
		cout<<f(0,0)<<"\n";
	}
	
	return 0;
}