#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int k, n;
stack<char> st;
string s, res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> s;
	k = n - k;

	for (char c : s) {
		if (k) {
			if (st.size() && c == ')') {
				st.pop();
				k -= 2;
			} else {
				st.push(c);
			}
		} else {
			st.push(c);
		}
	}

	while (st.size()) {
		res.push_back(st.top());
		st.pop();
	}

	reverse(ALL(res));
	cout << res << endl;

	return 0;
}