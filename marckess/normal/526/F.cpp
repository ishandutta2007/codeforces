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
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005, inf = 1000000000;
int n, a[MX];
int mn[4 * MX], cn[4 * MX], lz[4 * MX];
ll res;

void build (int i, int j, int pos) {
	mn[pos] = inf;
	cn[pos] = j - i + 1;

	if (i < j) {
		int m = (i + j) / 2;
		build(i, m, pos * 2);
		build(m + 1, j, pos * 2 + 1);
	}
}

void push (int i, int j, int pos) {
	if (i < j) {
		lz[pos * 2] += lz[pos];
		lz[pos * 2 + 1] += lz[pos];
	}
	
	mn[pos] += lz[pos];
	lz[pos] = 0;
}

void update (int i, int j, int pos, int a, int b, int k) {
	if (lz[pos]) push(i, j, pos);
	
	if (j < a || b < i) return;
	
	if (a <= i && j <= b) {
		lz[pos] = k;
		push(i, j, pos);
		return;
	}

	int m = (i + j) / 2;
	update(i, m, pos * 2, a, b, k);
	update(m + 1, j, pos * 2 + 1, a, b, k);

	if (mn[pos * 2] < mn[pos * 2 + 1]) {
		mn[pos] = mn[pos * 2];
		cn[pos] = cn[pos * 2];
	} else if (mn[pos * 2] > mn[pos * 2 + 1]) {
		mn[pos] = mn[pos * 2 + 1];
		cn[pos] = cn[pos * 2 + 1];
	} else {
		mn[pos] = mn[pos * 2];
		cn[pos] = cn[pos * 2] + cn[pos * 2 + 1];
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	stack<int> inc, dec;
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int r, c;
		cin >> r >> c;
		a[r] = c;
	}

	build(1, n, 1);

	for (int i = 1; i <= n; i++) {
		update(1, n, 1, i, i, -inf);
		if (i > 1) update(1, n, 1, 1, i - 1, -1);

		while (inc.size() && a[inc.top()] < a[i]) {
			int j = inc.top();
			inc.pop();
			update(1, n, 1, inc.size() ? inc.top() + 1 : 1, j, a[i] - a[j]);
		}
		inc.push(i);

		while (dec.size() && a[dec.top()] > a[i]) {
			int j = dec.top();
			dec.pop();
			update(1, n, 1, dec.size() ? dec.top() + 1 : 1, j, a[j] - a[i]);
		}
		dec.push(i);

		if (mn[1] == 0) res += cn[1];
	}

	cout << res << endl;

	return 0;
}