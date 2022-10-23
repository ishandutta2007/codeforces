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

int x,r[60];
PII b[60];
bool solve() {
	scanf("%d",&x);
	VI g2;
	rep(i,0,x) {
		scanf("%d",&b[i].fi);
		b[i].fi++;
		b[i].se=i;
		if (b[i].fi>2) g2.pb(b[i].fi);
	}
	sort(b,b+x);
	if (SZ(g2)>=3) return 0;
	sort(all(g2));
	if (SZ(g2)==2&&g2!=VI{3,3}) return 0;
	if (SZ(g2)==1&&g2[0]>=5) return 0;
	auto expand=[&](vector<BI> &ps) {
		auto qs=ps;
		for (int i=0;i<SZ(ps);i++) {
			ps[i].pb(i%2);
			qs[i].pb((i+1)%2);
		}
		int m=SZ(ps[0]);
		BI x=BI(m-1,0)+BI{1},y=BI{1}+BI(m-1,0);
		rep(i,0,SZ(ps)) if (ps[i]==y) ps[i]=x;
		rep(i,0,SZ(ps)) if (qs[i]==y) qs[i]=x;
		ps.pb(y);
		for (auto x:qs) ps.pb(x);
	};
	vector<BI> ps;
	if (SZ(g2)==2) {
		ps=vector<BI>{{1,2},{0,1},{2,2},{1,0},{2,0},{1,1},{0,2},{2,1}};
		for (int i=0;i<x-SZ(g2);i++) expand(ps);
	} else if (SZ(g2)==1&&g2[0]==4) {
		ps=vector<BI>{{2},{1},{3}};
		for (int i=0;i<x-SZ(g2);i++) expand(ps);
	} else if (SZ(g2)==1&&g2[0]==3) {
		ps=vector<BI>{{2},{1}};
		if (x-SZ(g2)>=1) {
			ps=vector<BI>{{2,0},{1,0},{1,1},{0,1},{2,1}};
			for (int i=0;i<x-SZ(g2)-1;i++) expand(ps);
		}
	} else {
		ps=vector<BI>{{1}};
		for (int i=1;i<x;i++) {
			auto qs=ps;
			for (int j=0;j<SZ(ps);j++) {
				ps[j].pb((j+1)%2);
				qs[j].pb(j%2);
			}
			reverse(all(qs));
			ps.insert(ps.begin(),BI(i,0)+BI{1});
			for (auto y:qs) ps.pb(y);
		}
	}
	assert(SZ(set<BI>(all(ps)))==SZ(ps));
	for (int i=0;i<SZ(ps);i++) {
		int sx=0;
		reverse(all(ps[i]));
		rep(j,0,x) {
			r[b[j].se]=ps[i][j];
			if (i>=1) sx+=min(ps[i][j],ps[i-1][j]);
		}
		rep(j,0,x) printf("%d%c",r[j]," \n"[j==x-1]);
		assert(i==0||sx==1);
	}
	return 1;
}
int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		if (!solve()) puts("-1");
	}
}