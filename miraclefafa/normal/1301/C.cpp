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
int _;
ll n,m;

int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%lld%lld",&n,&m);
		int p1=n-m,p2=m+1;
		ll ss=n*(n+1)/2;
		ll c0=p1/p2,c1=p1/p2+1;
		ss-=c1*(c1+1)/2*(p1%p2)+c0*(c0+1)/2*(p2-p1%p2);
		printf("%lld\n",ss);
	}
}