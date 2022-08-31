#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head


typedef double db;
const db EPS = 1e-9;
int W=100000;
inline int sign(db a) { return a < -EPS ? -1 : a > EPS; }
inline int cmp(db a, db b){ return sign(a-b); }
struct P {
	db x, y;
	P() {}
	P(db _x, db _y) : x(_x), y(_y) {}
	P operator+(P p) { return {x + p.x, y + p.y}; }
	P operator-(P p) { return {x - p.x, y - p.y}; }
	P operator*(db d) { return {x * d, y * d}; }
	P operator/(db d) { return {x / d, y / d}; }
	bool operator<(P p) const {
	int c = cmp(x, p.x);
	if (c) return c == -1;
	return cmp(y, p.y) == -1;
	}
	bool operator==(P o) const{
	return cmp(x,o.x) == 0 && cmp(y,o.y) == 0;
	}
	db dot(P p) { return x * p.x + y * p.y; }
	db det(P p) { return x * p.y - y * p.x; }
	db distTo(P p) { return (*this-p).abs(); }
	db abs() { return sqrt(abs2());}
	db abs2() { return x * x + y * y; }
	void write() {
		printf("%d %d\n",int(x+0.1),int(y+0.1));
	}
};
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

vector<P> convexHull(vector<P> ps) {
	int n = ps.size(); if(n <= 1) return ps;
	sort(ps.begin(), ps.end());
	vector<P> qs(n * 2); int k = 0;
	for (int i = 0; i < n; qs[k++] = ps[i++]) while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
	for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--]) while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
	qs.resize(k - 1);
	return qs;
}
P circumCenter(P a, P b, P c) {
	P bb = b - a, cc = c - a;
	double db = bb.abs2(), dc = cc.abs2(), d = 2 * bb.det(cc);
	return a - P(bb.y * dc - cc.y * db, cc.x * db - bb.x * dc) / d;
}
int n,x[101000],y[101000],v[101000];
vector<P> q,r;
P vv[4];
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d%d",x+i,y+i,v+i);
		if (x[i]-v[i]>=0) q.pb(P(x[i]-v[i],y[i])); else q.pb(P(0,min(y[i]+v[i]-x[i],W))),q.pb(P(0,max(y[i]-v[i]+x[i],0)));
		if (x[i]+v[i]<=W) q.pb(P(x[i]+v[i],y[i])); else q.pb(P(W,min(y[i]+(v[i]+x[i]-W),W))),q.pb(P(W,max(y[i]-(v[i]+x[i]-W),0)));
		if (y[i]-v[i]>=0) q.pb(P(x[i],y[i]-v[i])); else q.pb(P(min(x[i]+(v[i]-y[i]),W),0)),q.pb(P(max(x[i]-(v[i]-y[i]),0),0));
		if (y[i]+v[i]<=W) q.pb(P(x[i],y[i]+v[i])); else q.pb(P(min(x[i]+(v[i]+y[i]-W),W),W)),q.pb(P(max(x[i]-(v[i]+y[i]-W),0),W));
	}
	r=convexHull(q);
	db ret=0;
	rep(i,0,SZ(r)) {
		P p=circumCenter(r[i],r[(i+1)%SZ(r)],r[(i+2)%SZ(r)]);
		if (p.distTo(r[i])>ret) {
			ret=p.distTo(r[i]);
			vv[0]=r[i]; vv[1]=r[(i+1)%SZ(r)]; vv[2]=r[(i+2)%SZ(r)];
		}
	}
	vv[0].write(); vv[1].write(); vv[2].write();
}