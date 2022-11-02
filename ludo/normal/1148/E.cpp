#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const int INF = 2147483647; // (1 << 30) - 1 + (1 << 30)
const ll LLINF = (1LL << 62) - 1 + (1LL << 62); // = 9.223.372.036.854.775.807
const double PI = acos(-1.0);

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

typedef pair<ll,ll> pll;

vector< tuple<int, int, int> > ans;

void run() {
	int n;
	cin >> n;

	vector<pll> A(n);
	REP(i, n) { cin >> A[i].x; A[i].y = i; }
	sort(all(A));

	vi I(n);
	REP(i, n) I[A[i].y] = i;

	vector<ll> T(n);
	REP(i, n) cin >> T[i];
	sort(all(T));

	ll S = 0;
	REP(i, n) S += T[i] - A[i].x;
	if (S != 0) { printf("NO\n"); return; }

	if (T[0] < A[0].x || T[n-1] > A[n-1].x) { printf("NO\n"); return; }

	vii av;
	REP(i, n) {
		if (A[i].x < T[i]) av.eb(T[i] - A[i].x, i);
		if (A[i].x <= T[i]) continue;

		// T[i] < A[i].x
		while (T[i] < A[i].x && !av.empty()) {
			ll inc = min((ll) av.back().x, A[i].x - T[i]);
			assert(inc > 0);

			ans.eb(A[av.back().y].y, A[i].y, inc);
			A[av.back().y].x += inc;
			A[i].x -= inc;

			av.back().x -= inc;
			if (av.back().x == 0) av.pop_back();
		}

		if (av.empty() && T[i] < A[i].x) { printf("NO\n"); return; }
	}
/* 
	int it = 0;
	for (int i = 0; i < n; i++) {
		if (A[i].x <= T[i]) continue; // al goed.
		ll nodig = A[i].x - T[i];
		while (nodig > 0 && it < i) {
			ll ander = T[it] - A[it].x;
			if (ander <= 0) { it++; continue; }
			ll inc = min(nodig, ander);
			if (inc != 0) {
				ans.eb(A[it].y, A[i].y, inc);
				nodig -= inc;
				A[it].x += inc;
				A[i].x -= inc;
			}
			it++;
		}
		if (nodig > 0) { printf("NO\n"); return; }
	}
*/
	printf("YES\n%d\n", ans.size());
	for (auto t : ans)
		printf("%d %d %d\n", 1+get<0>(t), 1+get<1>(t), get<2>(t));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	run();
	return 0;
}