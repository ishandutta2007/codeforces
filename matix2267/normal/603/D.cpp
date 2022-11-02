#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;

struct frac {
	ll x, y;
	frac() : x(0), y(1) {}
	frac(ll _x, ll _y) : x(_x), y(_y) {}
};

typedef frac D;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<D,D> pdd;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

struct p3 {
	int a,b,c;
	p3(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

frac mf(ll x, ll y) {
	if(y<0) { x*=-1; y*=-1; }
	ll g = __gcd(x,y);
	return frac(x/g, y/g);
}

frac operator+(frac a, frac b) { return mf(a.x*b.y + a.y*b.x, a.y*b.y); }
frac operator-(frac a, frac b) { return mf(a.x*b.y - a.y*b.x, a.y*b.y); }
frac operator*(frac a, frac b) { return mf(a.x*b.x, a.y*b.y); }
bool operator<(frac a, frac b) {
	ll aa = a.x/a.y;
	ll bb = b.x/b.y;
	if(aa != bb) return aa < bb;
	a.x %= a.y; b.x %= b.y;
	if(a.x == 0 || b.x == 0) return a.x < b.x;
	return frac(b.y, b.x) < frac(a.y, a.x);
}

pdd proj(p3 o) {
	int div = o.a * o.a + o.b * o.b;
	return pdd(mf(o.a * o.c, div), mf(o.b * o.c, div));
}

ll lcm(ll a, ll b) { return a / __gcd(a,b) * b; }

void solve() {
	int n, c0 = 0;
	ll ans = 0;
	scanf("%d",&n);
	vector<p3> L;
	fru(i,n) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(c==0) c0++;
		else L.pb(p3(a,b,c));
	}
	n = L.size();
	ans += n*c0*(c0-1)/2;
	vector<pdd> P(n);
	fru(i,n) P[i] = proj(L[i]);
//	fru(i,n) printf("%.lld/%lld %lld/%lld\n",P[i].x.x,P[i].x.y,P[i].y.x,P[i].y.y);
	fru(i,n) {
//		puts("step");
		vector<pll> V(i);
		fru(j,i) {
			pdd w = pdd(P[j].x - P[i].x, P[j].y - P[i].y);
			ll lc = lcm(w.x.y, w.y.y);
			w.x.x *= lc/w.x.y;
			w.y.x *= lc/w.y.y;
			frac f = mf(w.x.x, w.y.x);
			V[j] = pll(f.x,f.y);
		}
//		puts("step2");
		sort(ALL(V));
//		puts("step3");
		pll prev = pll(-1,-1); // whatever
		int numprev = 0;
		fru(j,V.size()) {
			if(V[j] == prev) ans += numprev;
			else numprev = 0;
			prev = V[j];
			numprev++;
		}
//		puts("step4");
	}
	printf("%lld\n",ans);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}