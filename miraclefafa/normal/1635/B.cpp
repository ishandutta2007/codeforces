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

const int N=201000;
int n,a[N],loc[N];
void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	int ans=0;
	rep(i,0,n+2) loc[i]=0;
	rep(i,2,n) if (a[i]>a[i-1]&&a[i]>a[i+1]) loc[i]=1;
	rep(i,2,n) if (loc[i]) {
		if (i+2<n&&loc[i+2]) {
			a[i+1]=max(a[i],a[i+2]);
			loc[i]=loc[i+2]=0;
			ans++;
		} else {
			a[i]=max(a[i-1],a[i+1]);
			loc[i]=0;
			ans++;
		}
	}
	printf("%d\n",ans);
	rep(i,1,n+1) printf("%d ",a[i]); puts("");
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}