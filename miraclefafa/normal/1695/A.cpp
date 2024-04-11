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
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=2100;
const int inf=1<<30;
int _,n,m,a[N][N];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&m);
		int mx=-inf;
		rep(i,1,n+1) rep(j,1,m+1) {
			scanf("%d",&a[i][j]);
			mx=max(mx,a[i][j]);
		}
		rep(i,1,n+1) rep(j,1,m+1) a[i][j]=(a[i][j]==mx?1:0);
		rep(i,1,n+1) rep(j,1,m+1) a[i][j]+=a[i][j-1];
		rep(i,1,n+1) rep(j,1,m+1) a[i][j]+=a[i-1][j];
		int ans=n*m;
		rep(h,1,n+1) rep(w,1,m+1) {
			bool val=1;
			rep(i,1,n-h+2) rep(j,1,m-w+2) {
				val&=(a[i+h-1][j+w-1]-a[i-1][j+w-1]-a[i+h-1][j-1]+a[i-1][j-1])>0;
			}
			if (val) ans=min(ans,h*w);
		}
		//printf("zz %d %d\n",n,m);
		printf("%d\n",ans);
	}
}