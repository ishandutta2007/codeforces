#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define rs resize

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e9;
const int HCOORD = 1e5 + 10;
const int MAXCOORD = 2 * HCOORD;

int N;
vector<ii> ps[2];

int minl[MAXCOORD], maxl[MAXCOORD];
int minr[MAXCOORD], maxr[MAXCOORD];

ll calc(const vector<ii> &pts)
{
	/* cerr << "POINTS: ";
	for (ii pt : pts) cerr << "(" << pt.x << ", " << pt.y << "), ";
	cerr << endl; */
	for (ii pt : pts) {
		assert(0 <= pt.x && pt.x < MAXCOORD);
		assert(0 <= pt.y && pt.y < MAXCOORD);
	}

	fill_n(minl, MAXCOORD, INF);
	fill_n(maxl, MAXCOORD, -INF);
	fill_n(minr, MAXCOORD, INF);
	fill_n(maxr, MAXCOORD, -INF);

	for (ii pt : pts) {
		minl[pt.x + 1] = min(minl[pt.x + 1], pt.y + 1);
		maxl[pt.x + 1] = max(maxl[pt.x + 1], pt.y);
		minr[pt.x] = min(minr[pt.x], pt.y + 1);
		maxr[pt.x] = max(maxr[pt.x], pt.y);
	}

	for (int i = 1; i < MAXCOORD; i++) {
		minl[i] = min(minl[i - 1], minl[i]);
		maxl[i] = max(maxl[i - 1], maxl[i]);
	}
	for (int i = MAXCOORD - 1; --i >= 0; ) {
		minr[i] = min(minr[i], minr[i + 1]);
		maxr[i] = max(maxr[i], maxr[i + 1]);
	}

	// sweep line
	ll sum = 0LL;
	for (int i = 0; i < MAXCOORD; i++) {
		int lo = max(minl[i], minr[i]);
		int hi = min(maxl[i], maxr[i]);

		if (lo <= hi) {
			// cerr << i << ": " << minl[i] << " " << minr[i] << " " << maxl[i] << " " << maxr[i] << endl;
			// cerr << i << ": " << lo << " " << hi << endl;
		}

		int inc = max(0, hi - lo + 1);
		sum += inc;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	cin >> N;
	REP(i, N) {
		int x, y;
		cin >> x >> y;

		x += HCOORD;
		y += HCOORD;
		// 0 <= x,y < MAXCOORD
		ps[(x + y) % 2].eb((x + y) / 2, (x + MAXCOORD - y) / 2);
	}

	ll RET = 0;
	for (int par = 0; par < 2; par++)
		RET += calc(ps[par]);
	cout << RET << endl;
	return 0;
}