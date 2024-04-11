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

const int MX = 200005;
int n, b[MX], q[MX];
multiset<int> df;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	scanf("%d ", &n);
	forn(i, n) scanf("%d ", &b[i]);
	iota(q, q+n, 0);
	sort(q, q+n, [&] (int i, int j) {
		return b[i] < b[j];
	});
	sort(b, b+n);
	if (n == 2) {
		cout << 1 << endl;
		return 0;
	}
	
	for (int i = 0; i + 1 < n; i++)
		df.insert(b[i+1] - b[i]);

	for (int i = 0; i < n; i++) {
		if (i) df.erase(df.find(b[i] - b[i-1]));
		if (i + 1 < n) df.erase(df.find(b[i+1] - b[i]));
		if (i && i + 1 < n) df.insert(b[i+1] - b[i-1]);

		auto it = df.end();
		it--;
		if (*df.begin() == *it) {
			cout << q[i] + 1 << endl;
			return 0;
		}

		if (i && i + 1 < n) df.erase(df.find(b[i+1] - b[i-1]));
		if (i) df.insert(b[i] - b[i-1]);
		if (i + 1 < n) df.insert(b[i+1] - b[i]);
	}

	cout << -1 << endl;

	return 0;
}