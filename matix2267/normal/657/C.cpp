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
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

void solve() {
	int n,k,b,c;
	scanf("%d%d%d%d",&n,&k,&b,&c);
	b = min(b,5*c);
	vi T(n); fru(i,n) scanf("%d",&T[i]);
	sort(ALL(T));
	ll best = 1000000009000000018LL;
	fru(h,5) {
		ll cost = 0, tim = -1000000010 + h, sh = 0;
		priority_queue<ll> Q;
		fru(i,n) {
			ll ti2 = T[i];
			while((ti2-h)%5 != 0) ti2++;
			ll shift = (ti2 - tim)/5;
			cost += ll(Q.size()) * shift * b;
			tim = ti2; sh += shift;
			cost += (ti2 - T[i]) * c;
			Q.push((ti2 - T[i]) * c - sh * b);
			if(Q.size() > k) {
				cost -= Q.top() + sh * b;
				Q.pop();
			}
			if(Q.size() == k) best = min(best,cost);
		}
	}
	printf("%lld\n",best);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}