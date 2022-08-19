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

int _,n;
int gao(VI l,VI r) {
	printf("? %d %d\n",SZ(l),SZ(r));
	for (auto x:l) printf("%d ",x); puts("");
	for (auto x:r) printf("%d ",x); puts("");
	fflush(stdout);
	int w;
	scanf("%d",&w);
	return w;
}

void solve() {
	scanf("%d",&n);
	VI v{1};
	VI ans;
	for (int i=2;i<=n;i++) {
		int w=gao(v,VI{i});
		if (w!=0) {
			int l=0,r=i-1;
			while (l+1<r) {
				int mid=(l+r)/2;
				VI fl;
				rep(j,1,mid+1) fl.pb(j);
				if (gao(fl,VI{i})) r=mid; else l=mid;
			}
			rep(j,1,i+1) if (j!=r&&j!=i) ans.pb(j);
			rep(j,i+1,n+1) {
				if (gao(VI{j},VI{i})==0) ans.pb(j);
			}
			printf("! %d",SZ(ans));
			for (auto x:ans) printf(" %d",x);
			printf("\n");
			fflush(stdout);
			return;
		}
		v.pb(i);
	}
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}