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

const int MX = 100005;
int n, m, k, x[MX], y[MX], a, b, c, d;
ll tot, eli;
set<int> fil[MX], col[MX];

void go (int i, int j, int f) {
	int sig;
	if (f == 0) {
		auto it = fil[i].lower_bound(j);
		if (it != fil[i].end()) {
			sig = min(*it - 1, c);
		} else {
			sig = c;
		}
		
		if (sig == j) return;
		eli += sig - j;
		b = i + 1;
		go(i, sig, 1);

	} else if (f == 1) {
		auto it = col[j].lower_bound(i);
		if (it != col[j].end()) {
			sig = min(*it - 1, d);
		} else {
			sig = d;
		}

		if (sig == i) return;
		eli += sig - i;
		c = j - 1;
		go(sig, j, 2);

	} else if (f == 2) {
		auto it = fil[i].upper_bound(j);
		if (it != fil[i].begin()) {
			it--;
			sig = max(*it + 1, a);
		} else {
			sig = a;
		}

		if (sig == j) return;
		eli += j - sig;
		d = i - 1;
		go(i, sig, 3);

	} else if (f == 3) {
		auto it = col[j].upper_bound(i);
		if (it != col[j].begin()) {
			it--;
			sig = max(*it + 1, b);
		} else {
			sig = b;
		}

		if (sig == i) return;
		eli += i - sig;
		a = j + 1;
		go(sig, j, 0);
	}
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> x[i] >> y[i];
		fil[x[i]].insert(y[i]);
		col[y[i]].insert(x[i]);
	}

	tot = 1ll * n * m - k;
	a = 1, b = 1, c = m, d = n;
	go(1, 0, 0);

	if (tot == eli) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}