#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 0
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

template<typename T>
void max2(ll &a, ll a2, T &b, T b2) { if(a2>a) { a=a2; b=b2; } }

void solve() {
	int n,a,cf,cm; ll m;
	scanf("%d%d%d%d%lld",&n,&a,&cf,&cm,&m);
	vi A(n); fru(i,n) scanf("%d",&A[i]);
	vi A0 = A;
	sort(ALL(A));
	ll ans = 1LL*n*cf;
	ll best = -1;
	fru(i,n) m -= a-A[i];
	int cur1 = 0, cur2 = 0, lev = 0;
	while(m < 0) {
		assert(cur2!=n);
		m += a-A[cur2++];
		ans -= cf;
	}
	pair<pii,int> bestat(pii(-1,-1),-1);
	while(1) {
		DEB("-cur %d %d, lev %d, ans %lld\n",cur1,cur2,lev,ans);
		while(cur1 < cur2 && lev == A[cur1]) cur1++;
		while(cur1 < cur2) {
			int nlev = min(A[cur1],
					cur1 ? int(min(lev+m/cur1,ll(inft))) : inft);
			if(nlev <= lev) break;
			m -= 1LL*(nlev-lev)*cur1;
			ans += 1LL*(nlev-lev)*cm;
			lev = nlev;
			while(cur1 < cur2 && lev == A[cur1]) cur1++;
		}
		DEB("+cur %d %d, lev %d, ans %lld\n",cur1,cur2,lev,ans);
		max2(best, ans, bestat, make_pair(pii(cur1,cur2),lev));
		if(cur1 == cur2) {
			int lev2 = lev + min(ll(a-lev), cur1 ? m/cur1 : inft);
			max2(best, ans + 1LL*(lev2-lev)*cm,
					bestat, make_pair(pii(cur1,cur2),lev2));
		}
		if(cur2 == n) break;
		m += a-A[cur2++];
		ans -= cf;
	}
	assert(bestat.y != -1);
	printf("%lld\n",best);
	vector<pii> A1(n); fru(i,n) A1[i] = pii(A0[i],i);
	sort(ALL(A1));
	fru(i,n) if(i >= bestat.x.y) A0[A1[i].y] = a;
	for(int aa : A0) printf("%d ", max(aa, bestat.y));
	puts("");
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}