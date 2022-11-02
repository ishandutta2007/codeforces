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

const int maxn = 3e5 + 10;
int N, K, A[maxn];
bool canreach[maxn];


bool cansplit(int sum)
{
	fill_n(canreach, N + 1, false);
	canreach[0] = true;
	int lastR = -1;

	for (int L = 0, R = 0; L < N; L++) {
		while (R < N && A[R] - A[L] <= sum) R++;

		// interval [L, R) maximal w.r.t. S <= sum for given L
		// process(L, R);
		int len = R - L;
		if (canreach[L] && len >= K) {
			int from = max(L + K, lastR + 1), to = R;
			while (from <= to) {
				canreach[from] = true;
				from++;
			}
			lastR = R;
		}
	}
	return canreach[N];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);

	// rep(i, 0, N) cerr << A[i] << " ";
	// cerr << endl;

	int lo = -1, hi = 1e9 + 1;
	// assert(!cansplit(lo) && cansplit(hi));
	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		if (cansplit(mid))
			hi = mid;
		else
			lo = mid;
	}
	// assert(!cansplit(lo) && cansplit(hi));
	cout << hi << endl;

	return 0;
}