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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

string s;
int res;
stack<char> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	for (char c : s) {
		if (c == '{' || c == '(' || c == '[' || c == '<') {
			st.push(c);
		} else {
			if (st.empty()) {
				cout << "Impossible" << endl;
				return 0;
			}

			if (st.top() == '(' && c != ')') res++;
			if (st.top() == '<' && c != '>') res++;
			if (st.top() == '{' && c != '}') res++;
			if (st.top() == '[' && c != ']') res++;

			st.pop();
		}
	}

	if (st.size()) {
		cout << "Impossible" << endl;
		return 0;
	}

	cout << res << endl;

	return 0;
}