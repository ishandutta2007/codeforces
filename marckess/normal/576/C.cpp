#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1000005, SQ = 1000;
int n, x[MX], y[MX], b[MX], q[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		b[i] = x[i] / SQ;
	}

	iota(q, q+n, 1);
	sort(q, q+n, [&] (int i, int j) {
		if (b[i] != b[j]) return b[i] < b[j];
		if (b[i] % 2 == 0) return y[i] < y[j];
		return y[i] > y[j];
	});

	for (int i = 0; i < n; i++)
		cout << q[i] << " ";
	cout << endl;

	return 0;
}