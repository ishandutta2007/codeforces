#include <bits/stdc++.h>
 
//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 1005;
int n, k, in[MX];
vi s[MX];

void solve () {
	memset(in, -1, sizeof(in));

	cin >> n >> k;
	forn (i, k) {
		int c;
		cin >> c;
		s[i].resize(c);
		forn (j, c) {
			cin >> s[i][j];
			in[s[i][j]] = i;
		}
	}

	int mx;
	cout << "? " << n;
	forn (i, n) cout << " " << i + 1;
	cout << endl;
	cin >> mx;
	if (mx == -1) exit(0);

	int i = 1, j = n;
	while (i < j) {
		int m = (i + j) / 2, r;

		cout << "? " << m;
		forn (i, m) cout << " " << i + 1;
		cout << endl;
		cin >> r;
		if (r == -1) exit(0);

		if (r == mx) j = m;
		else i = m + 1;
	}

	if (in[j] == -1) {
		cout << "!";
		forn (i, k) cout << " " << mx;
		cout << endl;
	} else {
		cout << "? " << n - int(s[in[j]].size());
		forn (i, n) if (in[i + 1] != in[j]) cout << " " << i + 1;
		cout << endl;

		int r;
		cin >> r;
		if (r == -1) exit(0);

		cout << "!";
		forn (i, k) cout << " " << (i == in[j] ? r : mx);
		cout << endl;
	}

	string s;
	cin >> s;
	if (s == "Incorrect") exit(0);
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}