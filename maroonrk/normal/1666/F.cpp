#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define repn(i,n) rng(i, 1, n+1)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define eb emplace_back
#define si(x) int(x.size())
#define a first
#define b second

template<class t>using vc=vector<t>;

using pi=pair<int,int>;
using vi=vc<int>;

const ll mod = 998244353;
int n, a[5005];
int dp[5005][5005], C[5005][5005];
void add(int &a, int b){
	a += b;
	if(a >= mod) a -= mod;
}

void slv(){
	cin >> n;
	repn(i, n) cin >> a[i];
	if(n == 2){
		if(a[1] == a[2]) cout<<0<<'\n';
		else cout<<1<<'\n';
		return;
	}
	rep(i, n+2) rep(k, n+2) dp[i][k] = 0;
	reverse(a+1, a+n+1);
	int j = 1;
	while(j <= n and a[1] == a[j]) j ++;
	//j-1
	if(j-1 > 1){
		cout<<0<<'\n';return;
	}
	else{
		dp[j-1][j-2] = 1;
	}
	
	int i=j;
	while(i <= n){
		while(j <= n and a[i] == a[j]) j ++;
		
		rep(k, n/2+1){
			if(dp[i-1][k] == 0) continue;
			if(i+k-1 == n){
				if(k >= j-i){
					add(dp[j-1][k-(j-i)], 1LL*dp[i-1][k]*C[k][j-i]%mod);
				}
			}
			else{
				if(k >= j-i){
					add(dp[j-1][k-(j-i)], 1LL*dp[i-1][k]*C[k][j-i]%mod);
				}
				if(k >= j-i-1){
					int A = 1;
					if(i+k-1 == n-3) A = 2;
					add(dp[j-1][k-(j-i-1)+A], 1LL*dp[i-1][k]*C[k][j-i-1]%mod);
				}
			}
		}
		i = j;
	}
	cout << dp[n][0] << '\n';
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	for(int i=0;i<5003;i++){
		rep(j, i+1){
			if(i==j or j==0)C[i][j]=1;
			else C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	int t;cin>>t;
	rep(_,t)slv();
}