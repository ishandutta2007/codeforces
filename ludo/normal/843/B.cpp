#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 2147483647; // (1 << 30) - 1 + (1 << 30)
const ll LLINF = (1LL << 62) - 1 + (1LL << 62); // = 9.223.372.036.854.775.807
const double PI = acos(-1.0);

// lambda-expression: [] (args) -> retType { body }

#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const bool LOG = false;
void Log() {
	if(LOG) cerr << "\n\n";
}
template<class T, class... S>
void Log(T t, S... s) {
	if(LOG) cerr << t << "\t", Log(s...);
}

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int maxn = 50000;

int N, S, X;

bool asked[maxn] = {};
int val[maxn], seq[maxn];

// remember i : v[i] < x, v[i] maximal
// remember i : v[i] >= x, v[i] minimal
int bestLess, bestGeq = -1;

void query(int idx)
{
	if (asked[idx]) return;
	asked[idx] = true;
	cout << "? " << (idx + 1) << endl;
	cout.flush();
	cin >> val[idx] >> seq[idx];
	if (seq[idx] != -1) seq[idx]--;

	if (X <= val[idx] && (bestGeq == -1 || val[idx] < val[bestGeq])) {
		bestGeq = idx;
	}
	if (val[bestLess] < val[idx] && val[idx] < X) {
		bestLess = idx;
	}
	// cerr << "QUERIED " << idx << ": " << val[idx] << ", " << seq[idx] << endl;
	// cerr << "bestLess, bestGeq: " << bestLess+1 << ", " << bestGeq+1 << endl;
}

int run()
{
	default_random_engine G(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> rng(0, N - 1);

	query(S);
	if (val[S] >= X) return S;

	for (int i = 0; i < 1000; i++) {
		int idx = rng(G);
		query(idx);
	}
	for (int i = 0; i < 999; i++) {
		int nxt = seq[bestLess];
		if (nxt == -1) {
			assert(bestGeq == -1);
			return -1;
		}
		query(nxt);
		if (val[nxt] >= X) break;
	}
	return bestGeq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(10);

	cin >> N >> S >> X;
	S--;
	bestLess = S;
	bestGeq = -1;

	int ans = run();
	int ret = -1;
	if (ans != -1) ret = val[ans];
	cout << "! " << ret << endl;
	cout.flush();
	return 0;
}