#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, T, a[200005], t[200005], q[200005];

bool esPos (int m, bool f) {
	if (f)
		cout << m << endl << m << endl;

	ll acu = 0, cn = 0;
	for (int i = 0; i < n; i++) {
		int u = q[i];
	
		if (a[u] < m || cn == m)
			continue;

		acu += t[u];
		cn++;

		if (f)
			cout << u+1 << " ";
	}

	return cn == m && acu <= T;
}

int obtRes () {
	int i = 0, j = n+1, m = (i+j) / 2, rep = 25;

	while (rep--) {
		if (esPos(m, 0))
			i = m;
		else
			j = m;
		m = (i+j)/2;
	}

	if (esPos(i, 0))
		return i;
	return j;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> T;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> t[i];

	iota(q, q+n, 0);
	sort(q, q+n, [&] (int a, int b) {
		return t[a] < t[b];
	});

	esPos(obtRes(), 1);
	cout << endl;

	return 0;
}