#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef unsigned int uint;
typedef pair<uint, uint> ii;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) begin(v), end(v)
#define sz(v) ((int) (v).size())
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " \
	<< #x<< " = " << (x) << endl

template<class T> ostream& operator<<(ostream &os,
		const vector<T> &v) {
	os << "\n[";
	for(const T &x : v) os << x << ',';
	return os << "]\n";
}

namespace std { template<class T1, class T2>
	struct hash<pair<T1,T2>> { public:
		size_t operator()(const pair<T1,T2> &p) const {
			size_t x = hash<T1>()(p.x), y = hash<T2>()(p.y);
			return x ^ (y + 0x9e3779b9 + (x<<6) + (x>>2));
		}
	}; }

const int maxm = 10'000;
const int NODES = maxm * 1000;
constexpr ll INF = LLONG_MAX;

int n, m, g, r;

int p[maxm];

// distance:
ll d[maxm][1000];

vi queues[1000], nxt;

ll dijkstra() {
	nxt.pb(0);

	while (!nxt.empty()) {
		queues[0].swap(nxt);
		// nxt is empty

		REP(t, g) {
			while (!queues[t].empty()) {
				int pos = queues[t].back();
				queues[t].pop_back();

				if (pos == m-1) return d[pos][t];
				// fprintf(stderr, "d[%d][%d] = %d\n", pos, t, d[pos][t]);

				vector<pair<int, ii>> edg;
				if (pos > 0) {
					// move to the left
					int delta = p[pos] - p[pos-1];
					if (t+delta < g) {
						edg.eb(delta, ii(pos-1, t+delta));
					} else if (t+delta == g) {
						edg.eb(delta+r, ii(pos-1, 0));
					}
				}
				if (pos + 1 < m) {
					int delta = p[pos+1] - p[pos];
					if (t+delta < g) {
						edg.eb(delta, ii(pos+1, t+delta));
					} else if (t+delta == g) {
						edg.eb(delta + (pos==m-2 ? 0 : r), ii(pos+1, 0));
					}
				}

				for(auto e : edg) if (d[pos][t] + e.x < d[e.y.x][e.y.y]) {
					int toPos = e.y.x;
					int toT = e.y.y;
					// Q.erase(pair<ll,ii>(d[e.y.x][e.y.y], e.y));
					d[toPos][toT] = d[pos][t] + e.x;
					if (toT == 0)
						nxt.pb(toPos);
					else
						queues[toT].pb(toPos);
					// Q.emplace(d[e.y.x][e.y.y] = d[pos][t] + e.x, e.y);
				}
			}
		}
	}
	return (ll) INF;
}

signed main() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d", &p[i]);
	scanf("%d%d", &g, &r);

	/* srand(time(NULL));
	   n = 1000000; m = 10000;
	   REP(i, m) p[i] = 1 + (rand() % (n-1));
	   p[0] = 0;
	   p[1] = n;
	   g = 1000; r = 1000;
// */

	sort(p, p+m);

	REP(i, m) REP(j, g) d[i][j] = INF;
	d[0][0] = 0;

	ll res = dijkstra();
	if (res == INF) printf("-1\n");
	else printf("%lld\n", ll(res));
	return 0;
}