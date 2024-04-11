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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=5010;
int n,m,_,p[N];
PII v[N];
int a[20][N],dp[N],pd[N],ff[N],gg[N];

int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&m);
		rep(i,0,n) {
			rep(j,0,m) scanf("%d",&a[i][j]);
		}
		rep(j,0,m) {
			p[j]=0;
			rep(i,0,n) p[j]=max(p[j],a[i][j]);
			v[j]=mp(p[j],j);
		}
		sort(v,v+m); reverse(v,v+m);
		m=min(m,n);
		memset(dp,0,sizeof(dp));
		rep(i,0,m) {
			rep(j,0,(1<<n)) pd[j]=dp[j],dp[j]=0;
			int x=v[i].se;
			rep(rot,0,n) {
				rep(j,0,(1<<n)) ff[j]=pd[j];
				rep(k,0,n) {
					rep(j,0,(1<<n)) gg[j]=ff[j];
					rep(j,0,(1<<n)) if (j&(1<<k)) ff[j]=max(ff[j],gg[j-(1<<k)]+a[(k+rot)%n][x]);
				}
				rep(j,0,(1<<n)) dp[j]=max(dp[j],ff[j]);
			}
		}
		printf("%d\n",dp[(1<<n)-1]);
	}
}