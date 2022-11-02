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

const int maxn = 3e5 + 100, maxm = 2 * maxn;

int N, M, d[maxn], prv[maxm];
bool vis[maxn] = {}, needsFix[maxn] = {}, useEdge[maxm] = {};
pii edges[maxm];
vector<int> toE[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fill_n(prv, maxm, -1);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> d[i];
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[2*i].x = edges[2*i+1].y = u;
		edges[2*i].y = edges[2*i+1].x = v;
		toE[u].pb(2*i);
		toE[v].pb(2*i+1);
	}
	// edges[toE[i][j]].y has the direction
	
	bool hasm1 = false, solvable = true;
	for (int i = 0; i < N; i++) {
		hasm1 |= (d[i] < 0);
		if (d[i] == 1) solvable = !solvable;
	}
	
	// cerr << hasm1 << " AND " << solvable << endl;
	if (!hasm1 && !solvable) {
		cout << "-1" << endl;
		return 0;
	}

	int firstV = -1;
	for (int i = 0; i < N; i++) {
		if (d[i] == (hasm1 ? -1 : 1)) {
			firstV = i;
			break;
		}
	}

	// do bfs...
	queue<int> q;
	q.push(firstV);
	vis[firstV] = true;

	vi ordering;
	while (!q.empty()) {
		int cur = q.front();
#ifdef LOCAL
		cerr << "BFS " << cur << endl;
#endif
		q.pop();
		ordering.pb(cur);
		for (int edge : toE[cur]) {
			int nxt = edges[edge].y;
			if (vis[nxt]) continue;
			vis[nxt] = true;
			prv[nxt] = edge; // edges[edge].x == cur
			q.push(nxt);
		}
	}
	reverse(ordering.begin(), ordering.end());

	for (int i = 0; i < N; i++) {
		needsFix[i] = d[i] > 0;
		// cerr << needsFix[i] << " ";
	}
	// cerr << endl;
#ifdef LOCAL
	cerr << "ORDER: ";
	for (int o : ordering) cerr << (o+1) << " ";
	cerr << endl;
#endif
	for (int o : ordering) {
		if (!needsFix[o]) continue;

		// assert(o != firstV);
		int backedge = prv[o];
		useEdge[backedge] = !useEdge[backedge];
		// useEdge[backedge] = true;
		int par = edges[backedge].x;
		needsFix[par] = !needsFix[par];
#ifdef LOCAL
		cerr << "We need to fix " << (o+1) << ", and use edge " << ((backedge / 2)+1) << " to go to " << (par+1) << " (" << needsFix[par] << ")" << endl;
#endif
	}

	int cnt = 0;
	for (int i = 0; i < 2 * M; i++) {
		cnt += useEdge[i];
	}
	cout << cnt << endl;
	for (int i = 0; i < 2 * M; i++) {
		if (useEdge[i]) {
			cout << ((i+2) / 2) << endl;
		}
	}
#ifdef LOCAL
	cerr << "END OF TESTCASE" << endl;
#endif
	return 0;
}