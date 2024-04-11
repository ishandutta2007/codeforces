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

ll u,v;
int main() {
	scanf("%lld%lld",&u,&v);
	if ((v-u)%2!=0) {
		puts("-1");
		return 0;
	}
	if (u>v) {
		puts("-1");
		return 0;
	}
	if (u==0&&v==0) {
		puts("0");
		return 0;
	}
	if (u==v) {
		puts("1");
		printf("%lld\n",u);
		return 0;
	}
	ll p=(v-u)/2;
	ll q=u^p;
	if (p+q==v) {
		puts("2");
		printf("%lld %lld\n",p,q);
		return 0;
	}
	puts("3");
	printf("%lld %lld %lld\n",u,(v-u)/2,(v-u)/2);
}