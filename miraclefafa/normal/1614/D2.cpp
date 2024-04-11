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

const int M=20000000,N=20010000;
int n,x,cnt[N],p[N],prime[N/5];
ll dp[N],ans;
int d=0;

int tot=0;
void prime_table(int psize){
	int i,j,t1;
	for (i=1;i<=psize;i++) p[i]=i;
	for (i=2,tot=0;i<=psize;i++){
		if (p[i]==i) prime[++tot]=i;
		for (j=1;j<=tot && (t1=prime[j]*i)<=psize;j++){
			p[t1]=prime[j];
			if (i%prime[j]==0) break;
		}
	}
}

int main() {
	prime_table(M);
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d",&x);
		cnt[x]++;
	}
	rep(j,1,tot+1) {
		for (int c=M/prime[j];c>=1;c--) cnt[c]+=cnt[c*prime[j]];
	}
	dp[1]=cnt[1];
	rep(i,1,M+1) {
		for (int k=1;i*prime[k]<=M;k++) {
			int j=i*prime[k];
			dp[j]=max(dp[j],(ll)cnt[j]*(j-i)+dp[i]);
		}
		ans=max(ans,dp[i]);
	}
	printf("%lld\n",ans);
}