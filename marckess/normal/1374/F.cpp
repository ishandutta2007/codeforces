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

const int MX = 505;
int n, a[MX], b[MX];
vi res;

void update (int i) {
	res.pb(i - 2);
	swap(a[i], a[i - 1]);
	swap(a[i - 1], a[i - 2]);
}

void go () {
	while (1) {
		int to = -1, from;

		forn (i, n - 2) if (a[i] > b[i]) {
			to = i;
			forn (j, n)
				if (a[j] == b[i])
					from = j;
			break; 
		}

		if (to == -1) break;

		for (int i = from; i >= to + 2; i -= 2)
			update(i);

		if (from % 2 != to % 2) {
			update(to + 2);
			update(to + 2);
		}
	}
}

void solve () {
	cin >> n;
	res.clear();

	forn (i, n) {
		cin >> a[i];
		b[i] = a[i];
	}
	
	sort(b, b + n);

	go();

	if (a[n - 1] < a[n - 2]) {
		if (a[n - 1] == a[n - 3]) {
			update(n - 1);
		} else {
			int ind = -1;
			forn (i, n - 1) if (a[i] == a[i + 1]) ind = i;

			if (ind == -1) {
				cout << -1 << endl;
				return;
			}

			for (int i = n - 1 - (n % 2 != ind % 2); i >= ind + 2; i -= 2)
				update(i);
			update(ind + 2);

			go();
		}
	}

	/*forn (i, n) cout << a[i] << " ";
	cout << endl;*/

	cout << res.size() << endl;
	for (int x : res) cout << x + 1 << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}