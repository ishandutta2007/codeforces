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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

VI ret;
ll p;
int k;
int main() {
	scanf("%lld%d",&p,&k);
	while (p) {
		int r=p%k;
		if (r<0) r=k+r;
		p=(p-r)/(-k);
		ret.pb(r);
	}
	printf("%d\n",SZ(ret));
	for (auto c:ret) printf("%d ",c);
	puts("");
}