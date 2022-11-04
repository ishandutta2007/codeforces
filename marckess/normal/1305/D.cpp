#include <bits/stdc++.h>
 
//#define endl '\n'
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
typedef vector<ii> vii;

const int MX = 1005;
int n, d[MX];
vi adj[MX];
stack<int> st;

void ans (int u) {
	cout << "! " << u << endl;
	exit(0);
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
		d[a]++, d[b]++;
	}

	for (int i = 1; i <= n; i++)
		if (d[i] == 1)
			st.push(i);

	while (st.size() > 1) {
		int a = st.top();
		st.pop();

		int b = st.top();
		st.pop();

		cout << "? " << a << " " << b << endl;
		int lca;
		cin >> lca;

		if (lca == a) ans(a);
		if (lca == b) ans(b);

		for (int v : adj[a]) {
			d[v]--;
			if (d[v] == 1) st.push(v);
		}

		for (int v : adj[b]) {
			d[v]--;
			if (d[v] == 1) st.push(v);
		}
	}
	
	assert(st.size());
	ans(st.top());

	return 0;
}