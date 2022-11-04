#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 505;
int n, a[MX], d[MX], x = -1, y = -1, res = 0;
vi adj[MX];
stack<int> st, h;

bool insert (int u) {
	if (d[u] == a[u]) return 0;
	if (h.empty()) return 0;

	adj[u].pb(h.top());
	adj[h.top()].pb(u);
	d[u]++;
	d[h.top()]++;

	h.pop();

	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		if (a[i] > 1) {
			if (x == -1) x = i;
			y = i;

			if (st.size()) {
				adj[st.top()].pb(i);
				adj[i].pb(st.top());
				d[st.top()]++;
				d[i]++;
				res++;
			}

			st.push(i);
		} else {
			h.push(i);
		}
	}

	if (insert(x)) res++;
	if (insert(y)) res++;

	while (h.size()) {
		while (st.size() && d[st.top()] == a[st.top()])
			st.pop();

		if (st.empty()) break;

		insert(st.top());
	}

	if (h.size()) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << " " << res << endl;
	cout << n-1 << endl;
	for (int i = 1; i <= n; i++) {
		for (int j : adj[i])
			if (j < i)
				cout << i << " " << j << endl;
	}

	return 0;
}