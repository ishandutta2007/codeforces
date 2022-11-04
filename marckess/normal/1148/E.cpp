#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) emplace_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
 
const int MX = 300005;
int n, s[MX], t[MX], q[MX], ri[5*MX], rj[5*MX], d[5*MX], m = 0;	
stack<int> st;

void no () {
	cout << "NO" << endl;
	exit(0);
}
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		cin >> t[i];
 
	iota(q, q+n, 0);
	sort(q, q+n, [&] (int i, int j) {
		return s[i] < s[j];
	});
	sort(t, t+n);
 	

	for (int i = 0; i < n; i++) {
		if (s[q[i]] <= t[i]) st.push(i);
		else {
			while (s[q[i]] > t[i]) {
				if (st.empty()) no();
				int u = st.top();

				int e = min(t[u] - s[q[u]], s[q[i]] - t[i]);
				s[q[u]] += e;
				s[q[i]] -= e;

				ri[m] = q[u];
				rj[m] = q[i];
				d[m] = e;
				m++;

				if (s[q[u]] == t[u])
					st.pop();
			}
		}

		while (st.size()) {
			int u = st.top();
			if (s[q[u]] == t[u]) st.pop();
			else break;
		}
	}
 
	if (st.size()) no();
 
	cout << "YES" << endl;
	cout << m << endl;
	for (int i = 0; i < m; i++)
		cout << ri[i] + 1 << " " << rj[i] + 1 << " " << d[i] << endl;
 
	return 0;
}