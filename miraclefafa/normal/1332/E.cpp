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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

ll n,m,l,r;
int main() {
	scanf("%lld%lld%lld%lld",&n,&m,&l,&r);
	if (n<m) swap(n,m);
	if (n*m%2==1) {
		printf("%lld\n",powmod(r-l+1,n*m));
	} else {
		ll x=powmod(r-l+1,n*m);
		ll y=powmod((l-1)%2-r%2,n*m);
		x=(x+y)*(mod+1)/2%mod;
		if (x<0) x+=mod;
		printf("%lld\n",x);
	}
}