#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int query (int c, int d) {
	cout << "? " << c << " " << d << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

void ans (int a, int b) {
	cout << "! " << a << " " << b << endl;
	fflush(stdout);
	exit(0);
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	int a = 0, b = 0, d = query(0, 0);

	for (int i = 29; i >= 0 && d; i--) {
		int ant = d;
		d = query(a | (1 << i), b | (1 << i));
		
		if (ant != d) {
			if (ant == 1) {
				a |= (1 << i);
			} else {
				b |= (1 << i);
			}
			d = query(a, b);
		}
	}

	for (int i = 29; i >= 0; i--) {
		if (!(a & (1 << i)) && !(b & (1 << i))) {
			d = query(a, b | (1 << i));

			if (d == 1) {
				a |= 1 << i;
				b |= 1 << i;
			}
		}
	}

	ans(a, b);

	return 0;
}