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

const int N=301000;
int n,p[10];
ll calc(ll v) {
	p[0]=v/3, p[1]=(v+1)/3, p[2]=(v+2)/3;
	return 2*(p[0]*p[1]+p[0]*p[2]+p[1]*p[2]);
}
void solve() {
	scanf("%d",&n);
	ll l=0,r=100000;
	while (l+1<r) {
		ll md=(l+r)>>1;
		if (calc(md)>=n) r=md; else l=md;
	}
	printf("%lld\n",r);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}