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
typedef double D;
typedef pair<int,int> pii;
typedef pair<D,D> pdd;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

ll dist(ll x, ll y) { return x*x + y*y; }

D licz(pdd A, pdd B, D m) {
	D x = A.x*m + B.x*(1-m);
	D y = A.y*m + B.y*(1-m);
	return x*x + y*y;
}

D ternary(pdd A, pdd B) {
	D la1 = 0, la2 = 1;
	fru(i,100) {
		D mi1 = (2*la1 + la2)/3;
		D mi2 = (la1 + 2*la2)/3;
		D a1 = licz(A,B,mi1), a2 = licz(A,B,mi2);
		if(a1<a2) la2 = mi2;
		else la1 = mi1;
	}
	return licz(A,B,(la1+la2)/2);
}

void solve() {
	int n; pii q;
	scanf("%d%d%d",&n,&q.x,&q.y);
	vector<pii> P(n);
	fru(i,n) scanf("%d%d",&P[i].x,&P[i].y);
	ll mi = 1LL*inft*inft, ma = -1;
	for(pii p : P) {
		ll di = dist(p.x-q.x, p.y-q.y);
		mi = min(mi, di);
		ma = max(ma, di);
	}
	D dmi = mi;
	fru(i,n) {
		pii p1 = P[i], p2 = P[(i+1)%n];
		D best = ternary(pdd(p1.x-q.x, p1.y-q.y), pdd(p2.x-q.x, p2.y-q.y));
		dmi = min(dmi, best);
	}
//	printf("%lld -> %lf\n",mi,dmi);
	printf("%.9lf\n",acos(-1)*(ma-dmi));
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}