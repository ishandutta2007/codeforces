#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
#define all(v) (v).begin(), (v).end()
#define rs resize

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int INF = 2147483647; // (1 << 30) - 1 + (1 << 30)
const ll LLINF = (1LL << 62) - 1 + (1LL << 62); // = 9.223.372.036.854.775.807
const double PI = acos(-1.0);

// lambda-expression: [] (args) -> retType { body }

#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

#ifdef LOCAL
const bool LOG = true;
#else
const bool LOG = false;
#endif

void Log() {
	if(LOG) cerr << "\n\n";
}
template<class T, class... S>
void Log(T t, S... s) {
	if(LOG) cerr << t << "\t", Log(s...);
}

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int maxn = 5e5;
ll N, K, M;
vector<ii> vals;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	cin >> N >> K >> M;
	rep(i, 0, N) {
		int val;
		cin >> val;
		if (vals.empty() || vals.back().x != val) vals.eb(val, 1);
		else if (++vals.back().y == K) vals.pop_back();
	}

	N = 0;
	for (ii pr : vals) N += pr.y;

	ll ret = 1LL * N * M;
/*
	if (K >= N) {
		if (vals.size() == 1) ret %= K;
		cout << ret << endl;
		return 0;
	}
*/
	// now K < N
//	rep(i, 0, nvals) cerr << vals[i].x << ": " << vals[i].y << endl;

	int L = 0, R = vals.size() - 1;
	while (L <= R) {
		if (vals[L].x != vals[R].x) break;

		Log(L, R, vals[L].y, vals[R].y, M, K);
		if (L == R && (1LL * vals[L].y * M >= K)) {
			if ((1LL * vals[L].y * M) % K == 0) {
				ret = 0;
			} else {
				ll cnt = 1LL * vals[L].y * M;
				ret -= cnt - (cnt % K);
				// ret -= (1LL * vals[L].y * M) % K;
				// ret = (1LL * vals[L].y * M) % K;
				// ret = N - vals[L].y + (1LL * vals[L].y * M) % K;
			}
		} else {
			if (vals[L].y + vals[R].y < K) break;
			ret -= 1LL * (M - 1) * K;
			if (vals[L].y + vals[R].y > K) break;
		}
		L++;
		R--;
	}
	cout << ret << endl;
	return 0;
}