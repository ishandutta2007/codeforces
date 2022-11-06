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

const int MX = 1005;
int n, x[MX], y[MX], a[MX], b[MX];

bool isPos (int f, int g) {
	set<ii> st;

	for (int i = 0; i < n; i++)
		st.emplace(x[i], y[i]);

	for (int i = 0; i < n; i++) {
		ii z(f - a[i], g - b[i]);
		if (!st.count(z))
			return 0;
		st.erase(z);
	}

	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	

	cin >> n;
	forn(i,n) cin >> x[i] >> y[i];
	forn(i,n) cin >> a[i] >> b[i];

	for (int i = 0; i < n; i++)
		if (isPos(x[i] + a[0], y[i] + b[0])) {
			cout << x[i] + a[0] << " " << y[i] + b[0] << endl;
			return 0;
		}

	return 0;
}