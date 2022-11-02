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

const int maxn = 1e5 + 10, maxm = maxn;

int N, M, A[maxn], B[maxm], P[maxm];
vi demAt[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	vii order;
	cin >> N >> M;
	rep(i,1,N+1) {
		cin >> A[i];
		order.eb(-A[i], i);
	}
	rep(i,0,M) {
		cin >> B[i];
		order.eb(-B[i], maxn + i);
	}
	rep(i,0,M) cin >> P[i];

	sort(all(order));

	int last = 0;
	for (ii pr : order) {
		if (pr.y >= maxn) {
			// cerr << "B[i] " << (pr.y-maxn) << " at " << (last + 1) << endl;
			demAt[last].pb(P[pr.y - maxn]);
		} else {
			// cerr << "FOUND A[i]: " << pr.y << endl;
			last = max(last, pr.y);
		}
	}

	ll money = 0;
	int ans = 0;
	priority_queue<int> ps;
	for (int i = 1; i <= N; i++) {
		money += A[i];
		// choices: demAt[i]
		sort(all(demAt[i])); // sort by cost decreasingly

		for (int p : demAt[i]) {
			if (p <= money) {
				money -= p;
				ps.push(p);
				ans++;
			} else if (!ps.empty() && p < ps.top()) {
				money += ps.top() - p;
				ps.pop();
				ps.push(p);
			}
		}
	}
	cout << ps.size() << endl;
	return 0;
}