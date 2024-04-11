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

const int MAXN = 5001, SIGMA = 26;

int N;
string S;
vi idx[SIGMA];
int seen[SIGMA];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	cin >> S;
	N = S.size();
	S += S;

	REP(i, N) idx[S[i] - 'a'].pb(i);

	int sum = 0;

	REP(i, SIGMA) {
		// check every possible dx \in { 1, ..., N-1 }
		int mx = 0;
		for (int j = 1; j < N; j++) {
			fill_n(seen, SIGMA, 0);
			for (int k : idx[i]) {
				seen[S[j + k] - 'a']++;
			}
			int cnt = 0;
			REP(k, SIGMA) {
				if (seen[k] == 1) cnt++;
			}
			mx = max(mx, cnt);
		}
		sum += mx;
	}

	long double ret = sum;
	ret /= N;
	cout << ret << endl;
	
	return 0;
}