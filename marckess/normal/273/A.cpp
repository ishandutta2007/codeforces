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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX], m;
ll st[4 * MX], lz[4 * MX];

void push (int i, int j, int pos) {
	if (i < j) {
		lz[pos * 2] = lz[pos];
		lz[pos * 2 + 1] = lz[pos]; 
	}

	st[pos] = lz[pos];
	lz[pos] = 0;
}

void update (int i, int j, int pos, int a, int b, ll k) {
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

	st[pos] = max(st[pos * 2], st[pos * 2 + 1]);
}

ll query (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);
	if (j < a || b < i) return 0;
	if (a <= i && j <= b) return st[pos];

	int m = (i + j) / 2;
	return max(
		query(i, m, pos * 2, a, b),
		query(m + 1, j, pos * 2 + 1, a, b)
	);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(1, n, 1, i, i, a[i]);
	}

	cin >> m;
	while (m--) {
		int w, h;
		cin >> w >> h;

		ll r = query(1, n, 1, 1, w);
		cout << r << endl;
		update(1, n, 1, 1, w, r + h);
	}

	return 0;
}