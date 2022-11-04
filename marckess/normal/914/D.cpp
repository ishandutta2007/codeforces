#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int gcd (int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int n, a[500005], st[2000000], q, x, k, l, r, op;
int res = 2;

//-----------------Segment Tree---------------//
void constr (int i, int j, int pos) {
	if (i == j) {
		st[pos] = a[i];
		return;
	}

	int m = (i+j)/2;
	constr(i, m, pos*2);
	constr(m+1, j, pos*2+1);

	st[pos] = gcd(st[pos*2], st[pos*2+1]);
}

void update (int i, int j, int pos) {
	if (i > x || j < x)
		return;

	if (i == j) {
		st[pos] = a[i];
		return;
	}

	int m = (i+j)/2;
	update(i, m, pos*2);
	update(m+1, j, pos*2+1);

	st[pos] = gcd(st[pos*2], st[pos*2+1]);
}

void query (int i, int j, int pos) {
	if (i > r || j < l || !res)
		return;

	if (l <= i && j <= r) {
		if (gcd(st[pos], k) != k) {
			if (res == 1 || i == j) {
				res--;
			} else {
				int m = (i+j)/2;
				query(i, m, pos*2);
				query(m+1, j, pos*2+1);
			} 
		}
		return;
	}

	int m = (i+j)/2;
	query(i, m, pos*2);
	query(m+1, j, pos*2+1);
}
//--------------------------------------------//

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	constr (1, n, 1);

	cin >> q;
	while (q--) {
		cin >> op;

		if (op == 1) {
			cin >> l >> r >> k;
			
			res = 2;
			query(1, n, 1);
			if (res)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		} else {
			cin >> x >> k;
			
			a[x] = k;
			update(1, n, 1);
		}
	}

	return 0;
}