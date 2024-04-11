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
int n,x,cnt[22];
ll b[N];
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&x);
		rep(j,0,20) if ((x>>j)&1) cnt[j]++;
	}
	rep(j,0,20) {
		rep(i,0,cnt[j]) b[i]+=(1<<j);
	}
	ll ans=0;
	rep(i,0,n) ans+=(ll)b[i]*b[i];
	printf("%lld\n",ans);
}