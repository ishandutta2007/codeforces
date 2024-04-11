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

pii operator+(pii a,pii b) { return pii(a.x+b.x, a.y+b.y); }
pdd operator+(pii a,pdd b) { return pdd(a.x+b.x, a.y+b.y); }
pii operator-(pii a,pii b) { return pii(a.x-b.x, a.y-b.y); }
pii operator*(pii a,int b) { return pii(a.x*b, a.y*b); }
pdd operator*(pii a,D b) { return pdd(a.x*b, a.y*b); }
pii operator-(pii a) { return pii(-a.x,-a.y); }
ll kw(ll a) { return a*a; }
ll kw(int a) { return 1LL*a*a; }
D kw(D a) { return a*a; }
ll dist(pii a) { return kw(a.x)+kw(a.y); }
D dist(pdd a) { return kw(a.x)+kw(a.y); }

void solve() {
	pii o,p,w0,w1;
	int v,t;
	scanf("%d%d%d%d%d%d%d%d%d%d",&o.x,&o.y,&p.x,&p.y,&v,&t,
			&w0.x,&w0.y,&w1.x,&w1.y);
	p = p-o;
	w0 = -w0;
	w1 = -w1;
	if(dist(p+w0*t) < kw(v)*t*t) {
//		puts("first");
		D left = 0, right = t;
		fru(_,100) {
			D mid = (left+right)/2;
			if(dist(p+w0*mid) < kw(v)*mid*mid)
				right = mid;
			else left = mid;
		}
		printf("%.7lf\n",(left+right)/2);
	} else {
//		puts("second");
		p = p+w0*t;
//		printf("target %d %d\n",p.x,p.y);
		D left = 0, right = 1;
		while(dist(p+w1*right) > kw(v)*(t+right)*(t+right)) right *= 2;
		fru(_,200) {
			D mid = (left+right)/2;
			if(dist(p+w1*mid) < kw(v)*(t+mid)*(t+mid))
				right = mid;
			else left = mid;
		}
		printf("%.7lf\n",t+(left+right)/2);
	}
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}