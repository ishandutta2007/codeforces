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

const int N=1010;
int n,k,ans;
int g[N][N];

void dfs(int l,int r,int d) {
	if (l==r) return;
	ans=max(ans,d);
	int gr=(r-l+k)/k;
	for (int i=l;i<=r;i=i+gr) {
		int j=min(i+gr-1,r);
		dfs(i,min(i+gr-1,r),d+1);
		rep(p,l,i) rep(q,i,j+1) g[p][q]=d;
	}
}

int main() {
	scanf("%d%d",&n,&k);
	dfs(1,n,1);
	printf("%d\n",ans);
	rep(i,1,n+1) rep(j,i+1,n+1) printf("%d ",g[i][j]); puts("");
}