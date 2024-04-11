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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, a, b;

void no () {
	cout << "NO" << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> a >> b;

	if (a > 1 && b > 1) no();

	if (a == 1 && b == 1) {
		if (n == 2 || n == 3) no();

		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << (abs(i-j) == 1);
			cout << endl;
		}

		return 0;
	}

	int f = 0;
	if (a < b) {
		swap(a, b);
		f = 1;
	}
	a--;
	
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (i == j) cout << 0;
			else if (i < a || j < a) cout << f;
			else cout << 1-f;
		cout << endl;
	}

	return 0;
}