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

int preans=0;
ll n;
int ans[110];
int main() {
	set<int> s;
	s.insert(0);
	for (int n=1;n<=100;n++) {
		for (int p1=0;p1<=n;p1++)
			for (int p2=0;p1+p2<=n;p2++) 
					s.insert(4*p1+9*p2+49*(n-p1-p2));
		ans[n]=SZ(s);
//		printf("%d %d %d\n",n,SZ(s),SZ(s)-preans);
//		preans=SZ(s);
	}
	scanf("%lld",&n);
	if (n<=100) printf("%d\n",ans[n]);
	else printf("%lld\n",ans[100]+49ll*(n-100));
}