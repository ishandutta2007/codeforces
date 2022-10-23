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

int n,vis[10][10];
void solve() {
	scanf("%d",&n);
	rep(i,0,2) rep(j,0,2) vis[i][j]=0;
	vector<PII> st;
	rep(i,0,3) {
		int x,y;
		scanf("%d%d",&x,&y);
		vis[x%2][y%2]=1;
		st.pb(mp(x,y));
	}
	int x,y;
	scanf("%d%d",&x,&y);
	if (!vis[x%2][y%2]) {
		puts("NO");
		return;
	}
	PII cc;
	rep(i,0,3) {
		bool isc=1;
		rep(j,0,3) isc&=abs(st[i].fi-st[j].fi)+abs(st[i].se-st[j].se)<=1;
		if (isc) cc=st[i];
	}
	if (n>2&&(cc.fi==1||cc.fi==n)&&(cc.se==1||cc.se==n)) {
			puts((x==cc.fi||y==cc.se)?"YES":"NO");
	} else {
		puts("YES");
	}
}

int _;

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}