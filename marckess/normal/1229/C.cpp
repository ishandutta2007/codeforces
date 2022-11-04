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
int n, m, d[MX], q, v;
stack<int> st[MX];
ll res, x[MX];

void obtVal (int i) {
	x[i] = 1ll * d[i] * (d[i] - 1) / 2;
	x[i] -= 1ll * st[i].size() * (st[i].size() - 1) / 2;
	x[i] -= 1ll * (d[i] - st[i].size()) * (d[i] - st[i].size() - 1) / 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		st[a].push(b);
		d[a]++, d[b]++;
	}

	for (int i = 1; i <= n; i++) {
		obtVal(i);
		res += x[i];
	}

	cout << res << endl;

	cin >> q;
	while (q--) {
		cin >> v;
		res -= x[v];
		x[v] = 0;

		while (st[v].size()) {
			int u = st[v].top();
			st[v].pop();

			res -= x[u];
			st[u].push(v);
			obtVal(u);
			res += x[u];
		}

		cout << res << endl;
	}

	return 0;
}