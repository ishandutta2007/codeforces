#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int n,k,dp[N],tmp[N],ans[N];
int main() {
	scanf("%d%d",&n,&k);
	int s=0;
	dp[0]=1;
	for (int i=k;s<=n;s+=i,i++) {
		for (int j=1;j<=n;j++) {
			tmp[j]=0;
			if (j-i>=0) tmp[j]=(tmp[j-i]+dp[j-i])%mod;
		}
		rep(j,0,n+1) {
			dp[j]=tmp[j];
			ans[j]=(ans[j]+dp[j])%mod;
			//printf("%d %d %d\n",i,j,dp[j]);
		}
	}
	rep(i,1,n+1) printf("%d%c",ans[i]," \n"[i==n]);
}