#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
string s;

bool go (int i, int j) {
	int c = 0;
	stack<int> st;

	for (int k = i; k <= j; k++) {
		if (s[k] == '(') c++;
		else if (s[k] == ')') c--;
		else st.push(k);

		if (c < 0) {
			if (st.empty()) return 0;
			int u = st.top();
			st.pop();
			s[u] = '(';
			c++;
		}
	}

	if (c > 0) {
		for (int k = j; k >= i && c; k--)
			if (s[k] == '?')
				s[k] = ')', c--;
	}
	if (c) return 0;

	for (int k = i, f = 0; k <= j; k++) {
		if (s[k] == '(') c++;
		if (s[k] == ')') c--;
		if (s[k] == '?') {
			if (!f) s[k] = '(', c++;
			else s[k] = ')', c--;
			f ^= 1;
		}
		if (c < 0) return 0;
	}

	return c == 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;
	if (n % 2 || s[0] == ')' || s.back() == '(') {
		cout << ":(" << endl;
		return 0;
	}

	s[0] = '(', s.back() = ')';
	if (go(1, n - 2)) cout << s << endl;
	else cout << ":(" << endl;

	return 0;
}