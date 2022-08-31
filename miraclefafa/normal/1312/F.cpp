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

const int N=301000;
int _,n,p[10],wt[1100],pp;
int dp[1100][10];
ll a[N];
void solve() {
	for (int i=1;i<=500;i++) {
		int z=0;
		for (int j=0;j<3;j++) {
			set<int> sg;
			rep(k,0,3) if (j==0||k==0||j!=k) {
				if (i-p[k]>=0) sg.insert(dp[i-p[k]][k]);
				else sg.insert(0);
			}
			dp[i][j]=0;
			while (sg.count(dp[i][j])) dp[i][j]+=1;
			z=z*4+dp[i][j];
			//printf("%d ",dp[i][j]);
		}
		wt[i]=z;
	}
	for (int prd=1;prd<=30;prd++) {
		bool sm=1;
		for (int j=50;j<500;j++) if (j+prd<=500&&wt[j]!=wt[j+prd]) sm=0;
		if (sm) {
//			printf("%d %d %d %d\n",p[0],p[1],p[2],prd);
			pp=prd;
			return;
		}
	}
	assert(0);
}

int getsg(ll n,int way) {
	int st=0;
	if (n<=0) return 0;
	if (n>500) {
		n-=(n-500)/pp*pp;
		while (n>500) n-=pp;
	}
	return dp[n][way];
}

int main() {
	/*for (p[0]=1;p[0]<=5;p[0]++) for (p[1]=1;p[1]<=5;p[1]++) for (p[2]=1;p[2]<=5;p[2]++) 
		solve();*/
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		rep(i,0,3) scanf("%d",p+i);
		solve();
		int s=0;
		rep(i,0,n) {
			scanf("%lld",a+i);
			s^=getsg(a[i],0);
		}
		int ans=0;
		rep(i,0,n) rep(j,0,3) if ((s^getsg(a[i],0)^getsg(a[i]-p[j],j))==0) ans+=1;
		printf("%d\n",ans);
	}
}