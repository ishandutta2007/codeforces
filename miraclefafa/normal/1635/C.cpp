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
int n;
ll a[N];
void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%lld",a+i);
	vector<VI> ans;
	if (a[n-1]>a[n]) { puts("-1"); return; }
	per(i,1,n-1) {
		if (a[i]>a[i+1]) {
			ans.pb({i,i+1,n});
			a[i]=a[i+1]-a[n];
			if (a[i]>a[i+1]) { puts("-1"); return; }
		}
	}
	printf("%d\n",SZ(ans));
	for (auto x:ans) printf("%d %d %d\n",x[0],x[1],x[2]);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}