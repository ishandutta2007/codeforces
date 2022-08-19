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

const int N=401000;
int m,n,mat[N];
PII p[N],q[N];
ll cc[N];

void add(PII *q,int i,int l,int r,int v,int ty=0) {
	int pl=lower_bound(q,q+n,mp(l,-1))-q;
	int pr=lower_bound(q,q+n,mp(r+1,-1))-q-1;
//	printf("gg %d %d\n",pl,pr);
	if (pl>pr) return;
	if (ty==0) {
		pl-=i; pr-=i; 
	} else {
		swap(pl,pr); pl=i-pl; pr=i-pr;
	}
//	printf("add %d %d %d\n",pl,pr,v);
	if (pl>=0&&pr>=0) cc[pl]+=v,cc[pr+1]-=v;
	else if (pl<0&&pr<0) cc[pl+n]+=v,cc[pr+1+n]-=v;
	else {
		cc[pl+n]+=v; cc[n]-=v;
		cc[0]+=v; cc[pr+1]-=v;
	}
}

int main() {
	scanf("%d%d",&m,&n);
	rep(i,0,n) scanf("%d",&p[i].fi),p[i].se=i;
	rep(i,0,n) scanf("%d",&q[i].fi),q[i].se=i;
	sort(p,p+n); sort(q,q+n);
	rep(i,0,n) {
		add(q,i,p[i].fi-m,p[i].fi-m/2-1,m-p[i].fi);
		add(q,i,p[i].fi-m/2,p[i].fi-1,p[i].fi);
		add(q,i,p[i].fi,p[i].fi+m/2,-p[i].fi);
		add(q,i,p[i].fi+m/2+1,p[i].fi+m,p[i].fi+m);
	}
	rep(i,0,n) {
		add(p,i,q[i].fi-m,q[i].fi-m/2-1,-q[i].fi,1);
		add(p,i,q[i].fi-m/2,q[i].fi,q[i].fi,1);
		add(p,i,q[i].fi+1,q[i].fi+m/2,-q[i].fi,1);
		add(p,i,q[i].fi+m/2+1,q[i].fi+m,q[i].fi,1);
	}
	rep(i,1,n+1) cc[i]+=cc[i-1];
	int md=min_element(cc,cc+n)-cc;
	rep(i,0,n) mat[p[i].se]=q[(i+md)%n].se;
	printf("%lld\n",cc[md]);
	rep(i,0,n) printf("%d%c",mat[i]+1," \n"[i==n-1]);
}