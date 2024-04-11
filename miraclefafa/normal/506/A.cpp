#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=30100;
int dp[N][600];
int n,d,x,cnt[N];
int gao(int x,int w) {
	if (x>30000) return 0;
	if (dp[x][w-d+300]!=-1) return dp[x][w-d+300];
	else {
		int c=max(gao(x+w,w),gao(x+w,w+1));
		if (w>1) c=max(gao(x+w,w-1),c);
//		if (x<=30) printf("%d %d %d\n",x,w,cnt[x]+c);
		return dp[x][w-d+300]=cnt[x]+c;
	}
}
int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&n,&d);
	rep(i,0,n) {
		scanf("%d",&x);
		cnt[x]++;
	}
	printf("%d\n",gao(0,d));
}