#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const ld PI = acos(-1.0);
template<class T> using min_queue =
		priority_queue<T, vector<T>, greater<T>>;
template<class T> int sz(const T &x) {
	return (int) x.size(); // copy the ampersand(&)!
}

template<class T> ostream& operator<<(ostream &os, vector<T> v) {
	os << "\n[";
	for(T &x : v) os << x << ',';
	return os << "]\n";
}

struct pairhash {
public:
	template<typename T1, typename T2>
	size_t operator()(const pair<T1, T2> &p) const {
		size_t lhs = hash<T1>()(p.x);
		size_t rhs = hash<T2>()(p.y);
		return lhs ^ (rhs+0x9e3779b9+(lhs<<6)+(lhs>>2));
	}
};

bool run() {
	int n, m, ka, kb;
	cin >> n >> m >> ka >> kb;
	
	vi va, vb;

	REP(i, ka) {
		int x; cin >> x;
		va.pb(x);
	}
	REP(i, kb) {
		int x; cin >> x;
		vb.pb(x);
	}

	while (sz(va) < m-1) va.pb(1);
	while (sz(vb) < n-1) vb.pb(n+1);

	if (sz(va) > m-1) return false;
	if (sz(vb) > n-1) return false;

	vi deg(n+m+1, 1);
	for (int x : va) deg[x]++;
	for (int y : vb) deg[y]++;

	min_queue<int> leaves;
	for (int i = 1; i <= n+m; i++)
		if (deg[i] == 1) leaves.push(i);
	
	int ita = 0, itb = 0;

	printf("Yes\n");
	int count = 0;
	while (count < n+m - 2) {
		int cur = leaves.top();
		leaves.pop();

		int nxt;
		if (cur <= n) {
			nxt = vb[itb++];
		} else {
			nxt = va[ita++];
		}

		count++;
		printf("%d %d\n", cur, nxt);

		// deg[cur]--;
		deg[nxt]--;
		if (deg[nxt] == 1)
			leaves.push(nxt);
	}

	int cur = leaves.top(); leaves.pop();
	int nxt = leaves.top(); leaves.pop();

	printf("%d %d\n", cur, nxt);

	return true;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	if (!run()) cout << "No" << endl;
	return 0;
}