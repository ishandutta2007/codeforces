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

int _;
void solve() {
	int mx=1e9+1,mn=0;
	int n;
	scanf("%d",&n);
	map<PII,int> hs;
	map<int,int> hsl,hsr;
	rep(i,0,n) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (!hs.count(mp(x,y))) hs[mp(x,y)]=z;
		else hs[mp(x,y)]=min(hs[mp(x,y)],z);
		if (!hsl.count(x)) hsl[x]=z;
		else hsl[x]=min(hsl[x],z);
		if (!hsr.count(y)) hsr[y]=z;
		else hsr[y]=min(hsr[y],z);
		mx=min(mx,x); mn=max(mn,y);
		int ans=hsl[mx]+hsr[mn];
		if (hs.count(mp(mx,mn))) ans=min(ans,hs[{mx,mn}]);
		printf("%d\n",ans);
	}
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();

	}
}