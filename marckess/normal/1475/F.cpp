#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

struct satisfiability_twosat{
	int n;
	vector<vector<int>> imp;

	satisfiability_twosat(int n) : n(n), imp(2 * n) {}

	void add_edge(int u, int v){imp[u].push_back(v);}

	int neg(int u){return (n << 1) - u - 1;}

	void implication(int u, int v){
		add_edge(u, v);
		add_edge(neg(v), neg(u));
	}

	vector<bool> solve(){
		int size = 2 * n;
		vector<int> S, B, I(size);

		function<void(int)> dfs = [&](int u){
			B.push_back(I[u] = S.size());
			S.push_back(u);

			for(int v : imp[u])
				if(!I[v]) dfs(v);
				else while (I[v] < B.back()) B.pop_back();

			if(I[u] == B.back())
				for(B.pop_back(), ++size; I[u] < S.size(); S.pop_back())
					I[S.back()] = size;
		};

		for(int u = 0; u < 2 * n; ++u)
			if(!I[u]) dfs(u);

		vector<bool> values(n);

		for(int u = 0; u < n; ++u)
			if(I[u] == I[neg(u)]) return {};
			else values[u] = I[u] < I[neg(u)];

		return values;
	}
};

const int MX = 1005;
satisfiability_twosat *sat;
int n, a[MX][MX], b[MX][MX];

void read (int a[MX][MX]) {
	forn (i, n) forn (j, n) {
		char c;
		cin >> c;
		a[i][j] = c == '1';
	}
}

void solve () {
	cin >> n;
	
	read(a);
	read(b);
	
	sat = new satisfiability_twosat(2 * n);
	
	forn (i, n) forn (j, n) {
		if (a[i][j] == b[i][j]) {
			sat->implication(i, n + j);
			sat->implication(n + j, i);
		} else {
			sat->implication(i, sat->neg(n + j));
			sat->implication(sat->neg(n + j), i);
		}
	}
	
	auto v = sat->solve();
	if (v.size()) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}