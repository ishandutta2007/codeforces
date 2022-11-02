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

struct ST {
	vi val, lazy; int n;
	ST(int _n, vi init) : val(2 * _n), lazy(2 * _n), n(_n) {
		for (int i = 0; i < n; i++)
			val[i + n] = init[i];
		for (int i = n; --i > 0; )
			val[i] = val[2*i] + val[2*i+1];
	}

	void push(int idx, int nl, int nr) {
		if (lazy[idx]) {
			val[idx] = (nr - nl) - val[idx];
			// cerr << "EVAL LAZY [" << nl << ", " << nr << "): " << val[idx] << endl;
			if (idx < n) {
				lazy[2*idx] ^= 1;
				lazy[2*idx+1] ^= 1;
			}
			lazy[idx] = 0;
		}
	}

	void update(int idx, int nl, int nr, int ql, int qr) {
		if (ql <= nl && nr <= qr) {
			// update this now
			lazy[idx] ^= 1;
			this->push(idx, nl, nr);
			// cerr << "LAZY [" << nl << ", " << nr << "): " << val[idx] << endl;
			return;
		} else if (ql >= nr || qr <= nl) {
			this->push(idx, nl, nr);
			return;
		}
		int nm = (nl + nr) / 2;
		this->push(idx, nl, nr);
		this->update(2*idx, nl, nm, ql, qr);
		this->update(2*idx+1, nm, nr, ql, qr);
		val[idx] = val[2*idx]+val[2*idx+1];
		// cerr << "SET [" << nl << ", " << nr << "): " << val[idx] << endl;
	}

	void update(int l, int r) {
		this->update(1, 0, n, l, r);
	}

	int query(int idx, int nl, int nr, int ql, int qr) {
		this->push(idx, nl, nr);
		if (ql <= nl && nr <= qr) {
			// update this now
			// cerr << "QUERY [" << nl << ", " << nr << "): " << val[idx] << endl;
			return val[idx];
		} else if (ql >= nr || qr <= nl) return 0;
		int nm = (nl + nr) / 2;
		return this->query(2*idx, nl, nm, ql, qr)
			 + this->query(2*idx+1, nm, nr, ql, qr);
	}

	int query(int l, int r) {
		return this->query(1, 0, n, l, r);
	}
};

const int maxn = 1 << 18;
int N, lidx[maxn], ridx[maxn], order[maxn], age = 0;
vi E[maxn];

void dfs(int u)
{
	order[age] = u;
	lidx[u] = age++;
	for (int v : E[u]) dfs(v);
	ridx[u] = age;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 2; i <= N; i++) {
		int p;
		cin >> p;
		E[p].pb(i);
	}

	dfs(1);
	vi init(maxn, 0);
	for (int i = 1; i <= N; i++) {
		int t; cin >> t;
		init[lidx[i]] = t;
	}
	ST tree(maxn, init);

	/*for (int i = 1; i <= N; i++) {
		cerr << i << ": " << lidx[i] << ", " << ridx[i] << endl;
	}
	for (int i = 0; i < N; i++) 
		cerr << init[i] << " ";
	cerr << endl;
	*/

	int Q;
	cin >> Q;
	while (Q--) {
		int v; string s;
		cin >> s >> v;
		int l = lidx[v], r = ridx[v];
		if (s[0] == 'g') {
			cout << tree.query(l, r) << endl;
		} else {
			tree.update(l, r);
		}
	}
	return 0;
}