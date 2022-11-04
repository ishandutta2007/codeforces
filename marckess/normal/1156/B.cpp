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

void solve () {
	int n, cn[255] = {0};
	string s;
	cin >> s;
	n = s.size();
	for (char c : s) cn[c]++;
	s = "";

	for (int i = 'a'; i <= 'z'; i += 2)
		while (cn[i]) {
			s.pb(i);
			cn[i]--;
		}

	if (s.size() == n) {
		cout << s << endl;
		return;
	}

	int x = 'b';
	while (x <= 'z') {
		if (s.empty() || (cn[x] && abs(x - s.back()) > 1))
			break;
		x += 2;
	}

	if (x > 'z') {
		reverse(all(s));
		x = 'b';
		while (x <= 'z') {
			if (s.empty() || (cn[x] && abs(x - s.back()) > 1))
				break;
			x += 2;
		}
	}

	if (x > 'z') {
		cout << "No answer" << endl;
		return;
	}

	while (cn[x]) {
		s.pb(x);
		cn[x]--;
	}

	for (int i = 'b'; i <= 'z'; i += 2)
		while (cn[i]) {
			s.pb(i);
			cn[i]--;
		}

	cout << s << endl;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();	

	return 0;
}