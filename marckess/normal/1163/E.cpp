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

int n, m, s[200005];
vi a, b;

void add (int x) {
	int aux = x;
	for (int y : b)
		x = min(x, x ^ y);

	if (x) {
		a.pb(aux);
		b.pb(x);

		for (int i = b.size() - 1; i; i--)
			if (b[i] > b[i - 1])
				swap(b[i], b[i - 1]);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s+n, greater<int>());

	for (int i = 0; i < 20; i++) {
		a.clear(), b.clear();
		for (int j = 0; j < n; j++)
			if (s[j] < (1 << i))
				add(s[j]);

		if (a.size() == i) m = i;
	}

	a.clear(), b.clear();
	for (int j = 0; j < n; j++)
		if (s[j] < (1 << m))
			add(s[j]);
	reverse(all(a));

	cout << m << endl;
	for (int i = 1, x = 0, y = 0; i <= (1 << m); i++) {
		int sig = i ^ (i >> 1);
		cout << x << " ";

		for (int j = 0; j < m; j++)
			if ((1 << j) & (sig ^ y))
				x ^= a[j];

		y = sig;
	}
	cout << endl;

	return 0;
}