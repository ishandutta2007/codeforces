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

string s, res;
queue<char> a, b;

void solve () {
	cin >> s;
	res.clear();

	for (char c : s) {
		if (c % 2 == 0) a.push(c);
		else b.push(c);
	}

	while (a.size() || b.size()) {
		if (a.size() && (!b.size() || a.front() < b.front())) {
			res.push_back(a.front());
			a.pop();
		} else {
			res.push_back(b.front());
			b.pop();
		}
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}