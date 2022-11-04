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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, a[MX], res[MX];

void solve () {
	cin >> n;
	set<int> st;

	forn (i, n) {
		cin >> a[i];

		for (int j = 2; j * j <= a[i]; j++)
			if (a[i] % j == 0) {
				a[i] = j;
				st.insert(j);
				break;
			}
	}

	cout << st.size() << endl;
	int i = 1;
	for (int x : st) {
		forn (j, n) if (a[j] == x) res[j] = i;
		i++;
	}
	forn (i, n) cout << res[i] << " ";
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