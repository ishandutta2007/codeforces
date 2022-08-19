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

int n,cnt[110];
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		int x;
		scanf("%d",&x);
		cnt[__builtin_ctz(x)]++;
	}
	ll ans=0;
	rep(i,0,31) {
		int cc=0;
		rep(j,i+1,31) cc+=cnt[j];
		if (i==0) {
			ans=(ans+(powmod(2,cnt[0])-1)*powmod(2,cc))%mod;
		} else {
			if (cnt[i]>=2) ans=(ans+(powmod(2,cnt[i]-1)-1)*powmod(2,cc))%mod;
		}
	}
	printf("%lld\n",ans);
}