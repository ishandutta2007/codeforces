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

const int N=101000;
int n,m;
ll b[N],dp[N],pd[N];
vector<ll> num[70];
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%lld",b+i);
		per(j,0,60) if (b[i]&(1ll<<j)) { num[j].pb(b[i]); break; }
	}
	per(j,0,60) {
		int p1=0,p2=0,tot=0;
		ll cur=0;
		while (p1<m||p2<SZ(num[j])) {
			if (p1==m) {
				pd[tot++]=num[j][p2];
				if ((cur^num[j][p2])>cur) cur^=num[j][p2];
				else {
					puts("No");
					return 0;
				}
				p2++;
			} else if (p2==SZ(num[j])) {
//				printf("ff %d %lld\n",p1,dp[p1]);
				pd[tot++]=dp[p1];
				if ((cur^dp[p1])>cur) cur^=dp[p1];
				else {
					puts("No");
					return 0;
				}
				p1++;
			} else if ((cur^num[j][p2])>cur) {
				pd[tot++]=num[j][p2];
				cur^=num[j][p2];
				p2++;
			} else if ((cur^dp[p1])>cur) {
				pd[tot++]=dp[p1];
				cur^=dp[p1];
				p1++;
			} else {
				puts("No");
				return 0;
			}
		}
		m=tot;
		rep(i,0,m) dp[i]=pd[i];
//		rep(i,0,m) printf("%lld ",dp[i]); puts("");
	}
	puts("Yes");
	rep(i,0,m) printf("%lld ",dp[i]); puts("");
}