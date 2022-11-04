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

int n;
string s, t;
vi a, b;

int sort (string &s) {
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j + 1 < n; j++)
			if (s[j] > s[j+1]) {
				res++;
				swap(s[j], s[j+1]);
			}
	return res;
}

void solve () {
	cin >> n >> s >> t;
	a = vi(256), b = a;

	for (char c : s) a[c]++;
	for (char c : t) b[c]++;

	if (a != b) {
		cout << "NO" << endl;
		return;
	}

	if (*max_element(all(a)) > 1) {
		cout << "YES" << endl;
		return;
	}

	if (sort(s) % 2 == sort(t) % 2) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int q;
	cin >> q;
	while (q--)
		solve();

	return 0;
}