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

const int MX = 1000005;
int n, m;
ll a[MX], b[MX], cn[MX], res = 0;

void no () {
	cout << -1 << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		res += a[i] * m;
	}
	for (int i = 0; i < m; i++) cin >> b[i];

	sort(a, a+n);
	for (int i = 0; i < m; i++) {
		if (a[n-1] > b[i]) no();
		int j = upper_bound(a, a+n, b[i]) - a;
		if (!j) no();
		j--;
		res += b[i] - a[j];
		if (a[j] != b[i]) cn[j]++;
	}

	for (int i = 0; i < n; i++)
		if (cn[i] == m) {
			if (!i) no();
			res += a[i] - a[i-1];
			break;
		}

	cout << res << endl;

	return 0;
}