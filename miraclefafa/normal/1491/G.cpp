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

const int N=201000;
int n,a[N],vis[N];
vector<PII> op;
queue<VI> cyc;
void gao(int x,int y) {
	op.pb(mp(x,y));
	swap(a[x],a[y]);
	a[x]=-a[x]; a[y]=-a[y];
}
void gaoc2(VI c1,VI c2) {
	gao(c1[0],c2.back());
	rep(i,0,SZ(c2)-1) gao(c1[0],c2[i]);
	rep(i,1,SZ(c1)) gao(c1[i],c2.back());
	gao(c1[0],c2.back());
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	for (int i=1;i<=n;i++) if (!vis[i]) {
		VI c;
		int p=i;
		while (1) {
			c.pb(p);
			vis[p]=1;
			p=a[p];
			if (p==i) break;
		}
		cyc.push(c);
	}
	while (SZ(cyc)>=2) {
		VI c1=cyc.front(); cyc.pop();
		VI c2=cyc.front(); cyc.pop();
		gaoc2(c1,c2);
	}
	if (!cyc.empty()) {
		VI c1=cyc.front(); cyc.pop();
		if (SZ(c1)!=n) {
			rep(i,1,n+1) if (a[i]==i) {
				VI c2{i};
				gaoc2(c1,c2);
				break;
			}
		} else {
			gao(c1[0],c1[1]);
			rep(i,2,SZ(c1)-1) gao(c1[0],c1[i]);
			gao(c1[1],c1.back());
			gao(c1[0],c1.back());
			gao(c1[0],c1[1]);
		}
	}
	printf("%d\n",SZ(op));
	for (auto x:op) printf("%d %d\n",x.fi,x.se);
	rep(i,1,n+1) fprintf(stderr,"%d ",a[i]); fprintf(stderr, "\n");
}