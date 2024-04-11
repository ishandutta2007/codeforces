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

const int maxn = 1e5 + 10;

int N, M, h[maxn] = {}, lisl[maxn], lis_len[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	cin >> N >> M;
	REP(i, N) {
		int l, r;
		cin >> l >> r;
		h[l]++;
		h[r + 1]--;
	}

	// calculate the prefix sum
	rep(i, 1, M + 2) h[i] += h[i - 1];
	assert(h[0] == 0 && h[M + 1] == 0);

	// calculate leftwards LIS
	fill_n(lis_len, M, INF);
	for (int i = 1; i <= M; i++) {
		int idx = upper_bound(lis_len, lis_len + M, h[i]) - lis_len;
		lis_len[idx] = h[i];
		lisl[i] = idx + 1;
	}

	int ret = 0;
	fill_n(lis_len, M, INF);
	for (int i = M; i >= 1; i--) {
		int idx = upper_bound(lis_len, lis_len + M, h[i]) - lis_len;
		lis_len[idx] = h[i];
		ret = max(ret, idx + lisl[i]);
	}

	cout << ret << endl;
	return 0;
}