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

const int N=201000;
int n,v[N],q;
ll s[N],pre[N];
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&v[i]);
		s[i]=v[i]+s[i-1];
	}
	rep(i,1,n+1) {
		pre[i]=max(pre[i-1],(s[i]+i-1)/i);
	}
	scanf("%d",&q);
	rep(i,0,q) {
		int l=0,r=n+1;
		ll t;
		scanf("%lld",&t);
		while (l+1<r) {
			int md=(l+r)>>1;
			//i=1...md t>=s[i]/i
			if (md*t>=s[n]&&t>=pre[md]) r=md;
			else l=md;
		}
		if (r==n+1) r=-1;
		printf("%d\n",r);
	}
}