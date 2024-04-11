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

const int N=1010000;

int n,k;
void solve() {
	scanf("%d%d",&n,&k);
	int mxd=0;
	VI pos,neg;
	rep(i,0,n) {
		int x;
		scanf("%d",&x);
		if (x>0) pos.pb(x);
		else if (x<0) neg.pb(-x);
		mxd=max(mxd,abs(x));
	}
	sort(all(pos));
	sort(all(neg));
	ll ans=0;
	if (!pos.empty()) {
		for (int i=SZ(pos)-1;i>=0;i-=k) {
			ans+=2*pos[i];
		}
	}
	if (!neg.empty()) {
		for (int i=SZ(neg)-1;i>=0;i-=k) {
			ans+=2*neg[i];
		}
	}
	ans-=mxd;
	printf("%lld\n",ans);
}

int _;
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}