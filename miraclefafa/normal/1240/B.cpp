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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=301000;
int n,l[N],r[N],a[N],c[N],_;

int query(int x) {
	int s=0;
	for (;x;x-=x&-x) s=max(s,c[x]);
	return s;
}
void modify(int x,int s) {
	for (;x<=n;x+=x&-x) c[x]=max(c[x],s);
}

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) l[i]=n+1,r[i]=-1;
	rep(i,1,n+1) {
		scanf("%d",a+i);
		l[a[i]]=min(l[a[i]],i);
		r[a[i]]=max(r[a[i]],i);
	}
	vector<PII> zz;
	rep(i,1,n+1) {
		if (l[i]>r[i]) continue;
		zz.pb(mp(l[i],r[i]));
	}
	int ans2=0;
	int cc=0;
	rep(i,0,SZ(zz)) {
		if (i==0||zz[i].fi<zz[i-1].se) cc=1;
		else cc++;
		ans2=max(ans2,cc);
	}
	printf("%d\n",SZ(zz)-ans2);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}