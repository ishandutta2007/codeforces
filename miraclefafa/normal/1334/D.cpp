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

const int N=101000;
int _,n;
ll l,r,s[N];

int calc(ll x) {
	if (x>s[n-1]) return 1;
	auto a=lower_bound(s+1,s+n,x)-s;
	int b=x-s[a-1];
	if (b%2==1) return a;
	else return b/2+a;
}

int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%lld%lld",&n,&l,&r);
		rep(i,1,n+1) s[i]=s[i-1]+2*(n-i);
		for (ll i=l;i<=r;i++)
		 	printf("%d ",calc(i));
		puts("");
	}
}