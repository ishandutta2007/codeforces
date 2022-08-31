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

const int N=510;
int dp[N][N],f[N],a[N];
int n;
int gao(int l,int r) {
	if (dp[l][r]!=-1) return dp[l][r];
	if (l==r) {
		return dp[l][r]=a[l];
	}
	dp[l][r]=0;
	rep(k,l,r) {
		int f1=gao(l,k),f2=gao(k+1,r);
		if (f1!=0&&f2!=0&&f1==f2) dp[l][r]=f1+1;
	}
	return dp[l][r];
}

int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	memset(dp,-1,sizeof(dp));
	f[0]=0;
	rep(i,1,n+1) {
		f[i]=n+1;
		rep(j,0,i) if (gao(j,i-1)!=0) f[i]=min(f[i],f[j]+1);
	}
	printf("%d\n",f[n]);
}