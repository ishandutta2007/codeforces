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

int n, f;
string a, b;
vi res;
deque<char> q;

void solve () {
	cin >> n >> a >> b;

	while (q.size()) q.pop_back();
	res.clear();
	f = 0;

	for (char c : a) q.pb(c);

	for (int i = n - 1; i >= 0; i--) {
		if (f) {
			if (q.back() != b[i])
				res.pb(1);
			q.pop_back();
		} else {
			if (q.front() == b[i])
				res.pb(1);
			q.pop_front();
		}

		res.pb(i + 1);
		f ^= 1;
	}

	cout << res.size() << endl;
	for (int r : res)
		cout << r << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}