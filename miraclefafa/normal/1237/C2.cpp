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

const int N=50100;
int n,x[N],y[N],z[N];
map<int,vector<VI>> px;
map<int,vector<PII>> py;
vector<PII> ret,rm,mr;

void gao(vector<PII> x) {
	sort(all(x));
	for (int i=0;i+1<SZ(x);i+=2) {
		ret.pb(mp(x[i].se,x[i+1].se));
	}
	if (SZ(x)%2==1) rm.pb(x.back());
}

void gao(vector<VI> x) {
	py.clear();
	for (auto p:x) {
		py[p[0]].pb(mp(p[1],p[2]));
	}
	rm.clear();
	for (auto &p:py) gao(p.se);
	for (int i=0;i+1<SZ(rm);i+=2) {
		ret.pb(mp(rm[i].se,rm[i+1].se));
	}
	if (SZ(rm)%2==1) mr.pb(rm.back());
}

int main() {
	scanf("%d",&n);
	//n=1000;
	rep(i,0,n) {
		scanf("%d%d%d",x+i,y+i,z+i);
		px[x[i]].pb(VI{y[i],z[i],i+1});
	}
	for (auto &p:px) {
		gao(p.se);
	}
	for (int i=0;i+1<SZ(mr);i+=2) {
		ret.pb(mp(mr[i].se,mr[i+1].se));
	}
	for (auto p:ret) {
		printf("%d %d\n",p.fi,p.se);
	}
}