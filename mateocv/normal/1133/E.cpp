#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll dp[5010][5010],INF=-1ll*2e18;
ll a[5010],n;

ll f(ll x,ll y){
	if(y<0||x<-1)return INF;//ver lo de x<0
	if(x==-1)return 0;
	if(dp[x][y]>=0)return dp[x][y];
	if(y==0){
		dp[x][y]=0; return dp[x][y];
	}
	ll s=upper_bound(a,a+n,a[x]-6)-1-a;
	dp[x][y]=max(f(x-1,y),f(s,y-1)+x-s); return dp[x][y]; //????????
	
	
}

int main(){FIN;
	ll k; cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	memset(dp,-1,sizeof dp);
	cout<<f(n-1,k);
	
	return 0;
}