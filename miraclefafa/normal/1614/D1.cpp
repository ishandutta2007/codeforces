#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int M=5000000,N=5010000;
int n,x,cnt[N];
ll dp[N],ans;
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d",&x);
		cnt[x]++;
	}
	for (int i=1;i<=M;i++) {
		for (int j=i+i;j<=M;j+=i) cnt[i]+=cnt[j];
	}
	dp[1]=cnt[1];
	rep(i,1,M+1) {
		for (int j=i*2;j<=M;j+=i)
			dp[j]=max(dp[j],(ll)cnt[j]*(j-i)+dp[i]);
		ans=max(ans,dp[i]);
		//if (i<=10) printf("%d %lld\n",i,dp[i]);
	}
	printf("%lld\n",ans);
}