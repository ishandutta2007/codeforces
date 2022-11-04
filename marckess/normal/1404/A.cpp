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

const int MX = 300005;
int n, k;
string s;

void solve () {
	cin >> n >> k >> s;
	
	forn (i, k) {
		int x = 0, y = 0;
		for (int j = i; j < n; j += k) {
			if (s[j] == '0') x++;
			if (s[j] == '1') y++;
		}
		if (x && y) {
			cout << "NO" << endl;
			return;
		}
		if (x) {
			for (int j = i; j < n; j += k)
				s[j] = '0';
		}
		if (y) {
			for (int j = i; j < n; j += k)
				s[j] = '1';
		}
	}

	int x = 0, y = 0;
	forn (i, k) {
		if (s[i] == '0') x++;
		if (s[i] == '1') y++;
	}

	if (x <= k / 2 && y <= k / 2) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}