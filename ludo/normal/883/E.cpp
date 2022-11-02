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

const int maxm = 1001;
int N, M;
string S, A[maxm];

bool canAsk[26], forSure[maxm][26], result[26], isvalid[maxm] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	cin >> N >> S >> M;
	rep(i, 0, M) cin >> A[i];

	fill_n(canAsk, 26, true);
	fill_n(isvalid, M, true);

	vi stars;
	for (int i = 0; i < N; i++) {
		if (S[i] == '*') stars.pb(i);
		else canAsk[S[i] - 'a'] = false;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (S[j] != '*' && S[j] != A[i][j])
				isvalid[i] = false;
		}
		for (int j : stars) {
			int idx = A[i][j] - 'a';
			forSure[i][idx] = true;
			if (!canAsk[idx]) {
				isvalid[i] = false;
			}
		}
	}

	fill_n(result, 26, true);
	for (int i = 0; i < M; i++) {
		if (!isvalid[i]) continue;
		for (int j = 0; j < 26; j++) {
			result[j] = result[j] && forSure[i][j];
		}
	}

	int cnt = 0;
	rep(i, 0, 26) cnt += result[i];
	cout << cnt << endl;
	return 0;
}