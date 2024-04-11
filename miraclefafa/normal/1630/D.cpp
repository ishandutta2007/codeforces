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

const int N=1001000;
int n,k,a[N],m;

void solve() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) scanf("%d",a+i);
	int d=0;
	rep(i,0,m) {
		int x;
		scanf("%d",&x);
		d=gcd(d,x);
	}
	ll m0=0,m1=0;
	for (int i=0;i<d;i++) {
		ll p0=0,p1=-(1ll<<60);
		for (int y=i;y<n;y+=d) {
			ll q0=max(p0+a[y],p1-a[y]);
			ll q1=max(p1+a[y],p0-a[y]);
			p0=q0,p1=q1;
		}
		m0+=p0; m1+=p1;
		//printf("%lld %lld\n",p0,p1);
	}
	printf("%lld\n",max(m0,m1));
}
int _;
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}