#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

ll dp[100005][5];
ll amb[100005];
ll INF=1e18;
string s;
string hard="drah";

ll f(ll x, ll y){
	if(dp[x][y]>=0) return dp[x][y];
	if(y==4){
		dp[x][y]=INF; return dp[x][y];
	}
	if(x==0){
		dp[x][y]=0; return dp[x][y];
	}
	
	if(s[x-1]==hard[y]){
		dp[x][y]=min(f(x-1,y)+amb[x-1],f(x-1,y+1)); return dp[x][y];
	}
	dp[x][y]=f(x-1,y); return dp[x][y];
	
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n; cin>>n;
	cin>>s;
	//s="a"+s;
	fore(i,0,n) cin>>amb[i];
	memset(dp, -1, sizeof dp);
	cout<<f(n,0);
	
	return 0;
}