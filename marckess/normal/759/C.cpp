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
typedef vector<ii> vii;

const int MX = 100005;
int n, x[MX], lz[4 * MX];
ii mx[4 * MX];

void build (int i, int j, int pos) {
	mx[pos].se = i;
	
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

	mx[pos].fi += lz[pos];
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
	mx[pos] = max(mx[pos * 2], mx[pos * 2 + 1]);
}

int find (int i, int j, int pos) {
	if (lz[pos]) push(i, j, pos);
	if (mx[pos].fi < 1) return -1;
	if (i == j) return i;
	
	int m = (i + j) / 2;
	push(m + 1, j, pos * 2 + 1);
	if (mx[pos * 2 + 1].fi > 0) return find(m + 1, j, pos * 2 + 1);
	return find(i, m, pos * 2);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	build(1, n, 1);

	for (int i = 1; i <= n; i++) {
		int p, t;
		cin >> p >> t;

		if (t) {
			cin >> x[p];
			update(1, n, 1, 1, p, 1);
		} else {
			update(1, n, 1, 1, p, -1);
		}

		int res = find(1, n, 1);
		if (res != -1) res = x[res];
		cout << res << endl;
	}

	return 0;
}