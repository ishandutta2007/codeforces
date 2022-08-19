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

int n;
PII p[1010];
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&p[i].fi);
		p[i].se=i;
	}
	sort(p+1,p+n+1);
	int s=0;
	int l=1;
	int ans=-1;
	PII r(0,0);
	for (int i=1;i<=n;i++) {
		s+=p[i].fi;
		if (s==i*(i-1)/2) {
			if (p[i].se!=p[l].se&&p[i].fi-p[l].fi>ans) {
				ans=p[i].fi-p[l].fi;
				r=mp(p[l].se,p[i].se);
			}
			l=i+1;
		}
	}
	printf("! %d %d\n",r.fi,r.se);
}