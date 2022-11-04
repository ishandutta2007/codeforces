#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, p[MX], t, q;
stack<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	cin >> t;
	while (t--) {
		cin >> q;
		p[q] *= -1;
	}

	for (int i = n; i > 0; i--) {
		if (p[i] < 0) {
			st.push(-p[i]);
		} else {
			if (st.size() && st.top() == p[i])
				st.pop();
			else {
				st.push(p[i]);
				p[i] *= -1;
			}
		}
	}

	if (st.size()) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 1; i <= n; i++)
			cout << p[i] << " ";
		cout << endl;
	}

	return 0;
}