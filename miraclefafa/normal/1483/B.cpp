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

const int N=101000;
int n,a[N],l[N],r[N],_;
void solve() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	rep(i,0,n) r[i]=(i+1)%n,l[(i+1)%n]=i;
	set<PII> cop;
	rep(i,0,n) if (gcd(a[i],a[r[i]])==1) {
		cop.insert(mp(i,r[i]));
	}
	VI ans;
	int pos=0;
	while (!cop.empty()) {
		auto x=cop.lower_bound(mp(pos,-1));
		if (x==cop.end()) x=cop.begin();
		int pl=x->fi,pr=x->se;
		pos=r[pr];
		cop.erase(x);
		ans.pb(pr+1);
		if (pl==pr) break;
		l[r[pr]]=pl; r[pl]=r[pr];
		if (cop.count(mp(pr,r[pr]))) cop.erase(mp(pr,r[pr]));
		if (gcd(a[pl],a[r[pr]])==1) cop.insert(mp(pl,r[pr]));
	}
	printf("%d",SZ(ans));
	for (auto x:ans) printf(" %d",x); puts("");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}