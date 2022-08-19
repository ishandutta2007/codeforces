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

int n,W,_;
void solve() {
	scanf("%d%d",&n,&W);
	multiset<int> hs;
	rep(i,0,n) {
		int w;
		scanf("%d",&w);
		hs.insert(w);
	}
	int ans=0;
	while (!hs.empty()) {
		int r=W;
		while (1) {
			auto it=hs.upper_bound(r);
			if (it==hs.begin()) break;
			--it;
			r-=*it;
			hs.erase(it);
		}
		ans+=1;
	}
	printf("%d\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}