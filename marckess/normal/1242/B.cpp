#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, p[MX], cn;
set<int> adj[MX], st;

int parent (int a) {
	return p[a] == a ? a : p[a] = parent(p[a]);
}

bool join (int a, int b) {
	a = parent(a);
	b = parent(b);
	if (a == b) return 0;
	p[a] = b;
	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	for (int i = 1; i <= n; i++) {
		st.insert(i);
		p[i] = i;
	}

	while (st.size()) {
		queue<int> q;
		q.push(*st.begin());
		st.erase(st.begin());

		while (q.size()) {
			int u = q.front();
			q.pop();

			for (auto it = st.begin(); it != st.end();) {
				auto aux = it;
				aux++;

				if (!adj[u].count(*it)) {
					cn += join(u, *it);
					q.push(*it);
					st.erase(it);
				}

				it = aux;
			}
		}
	}

	cout << n - 1 - cn << endl;

	return 0;
}