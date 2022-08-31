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

int n,m;
ll ans=1,r=1;
int main() {
	scanf("%d%d",&n,&m);
	if (n==2) {
		puts("0");
		return 0;
	}
	for (int i=1;i<=m;i++) ans=ans*i%mod;
	for (int i=1;i<=n-1;i++) r=r*i%mod;
	for (int i=1;i<=m-n+1;i++) r=r*i%mod;
	ans=ans*powmod(r,mod-2)%mod*(n-2)%mod;
	ans=ans*powmod(2,n-3)%mod;
	printf("%lld\n",ans);
}