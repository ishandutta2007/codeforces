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

const int maxn = 35;
int N, M, A[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	cin >> N >> M;
	rep(i, 0, N) {
		cin >> A[i];
		A[i] %= M;
	}

	int mid = N / 2;

	vi l, r;
	rep(i, 0, 1 << mid) {
		int sum = 0;
		for (int j = i, k = 0; j > 0; j >>= 1, k++) {
			if (j & 1) {
				if ((sum += A[k]) >= M) sum -= M;
			}
		}
		l.pb(sum);
	}
	rep(i, 0, 1 << (N-mid)) {
		int sum = 0;
		for (int j = i, k = N; --k, j > 0; j >>= 1)
			if (j & 1) {
				if ((sum += A[k]) >= M) sum -= M;
			}
		r.pb(sum);
	}

	sort(all(l));
	l.resize(unique(all(l)) - l.begin());
	sort(all(r));
	r.resize(unique(all(r)) - r.begin());

	int nl = l.size(), nr = r.size();
	int pr = nr - 1, ret = 0;
	rep(pl, 0, nl) {
		while (l[pl] + r[pr] >= M) --pr;
		ret = max(ret, l[pl] + r[pr]);
	}
	cout << ret << endl;
	return 0;
}