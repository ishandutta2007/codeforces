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

const int maxn = 2e5 + 10;
int N, X[maxn], Y[maxn], H[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
	for (int i = 0; i < N; i++) Y[i] += X[i];

	H[0] = Y[0];
	for (int i = 1; i < N; i++)
		H[i] = min(H[i - 1] + 1, Y[i]);

	for (int i = N - 2; i >= 0; i--)
		H[i] = min(H[i + 1] + 1, H[i]);

	for (int i = 0; i < N; i++) {
		if (H[i] < X[i]) { cout << -1 << endl; return 0; }
	}

	/*for (int i = 1; i < N; i++) {
		assert(abs(H[i] - H[i - 1]) <= 1);
	}*/

	ll sumlawns = 0LL;
	for (int i = 0; i < N; i++) {
		sumlawns += H[i] - X[i];
	}
	cout << sumlawns << endl;
	for (int i = 0; i < N; i++) {
		if (i > 0) cout << " ";
		cout << H[i];
	}
	cout << endl;
	return 0;
}