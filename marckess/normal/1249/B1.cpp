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

const int MX = 200005;
int n, p[MX], res[MX];

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		res[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		if (res[i] == 0) {
			stack<int> st;
			int u = p[i];
			st.push(i);

			while (i != u) {
				st.push(u);
				u = p[u];
			}

			res[i] = st.size();
			while (st.size()) {
				res[st.top()] = res[i];
				st.pop();
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		solve();
	}

	return 0;
}