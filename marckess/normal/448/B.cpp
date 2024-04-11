#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int as[256], at[256];
string s, t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> t;

	for (char c : s) as[c]++;
	for (char c : t) at[c]++;

	if (s.size() == t.size()) {
		sort(ALL(s));
		sort(ALL(t));

		if (s == t) cout << "array" << endl;
		else cout << "need tree" << endl;

		return 0;
	}

	int j = 0;
	for (int c : s)
		if (j < t.size() && c == t[j])
			j++;

	if (j == t.size()) {
		cout << "automaton" << endl;
		return 0;
	}

	bool f = 1;
	for (int i = 'a'; i <= 'z'; i++)
		f &= as[i] >= at[i];

	if (f) cout << "both" << endl;
	else cout << "need tree" << endl;

	return 0;
}