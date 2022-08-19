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

const int inf=1<<30;
const int N=201000;

int a[N],b[N],n,_;

int solve(int x) {
	rep(i,1,n+1) if (a[i]==-1) b[i]=x; else b[i]=a[i];
	int ans=0;
	rep(i,2,n+1) ans=max(ans,abs(b[i]-b[i-1]));
	return ans;
}

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	int pl=0,pr=inf;
	while (pl+5<=pr) {
		int fl=(pl+(ll)pl+pr)/3,fr=(pl+(ll)pr+pr)/3;
		//printf("%d %d\n",fl,solve(fl));
		if (solve(fl)>solve(fr)) pl=fl; else pr=fr;
	}
	int ans=solve(pl),pans=pl;
	for (int j=pl+1;j<=pr;j++) {
		int w=solve(j);
		if (w<ans) ans=w,pans=j;
	}
	printf("%d %d\n",ans,pans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}