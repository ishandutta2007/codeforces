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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int x[MX], n, res[MX];
char op[MX];

int f (int k) {
	forn (i, n) {
		if (op[i] == '|') k |= x[i];
		if (op[i] == '^') k ^= x[i];
		if (op[i] == '&') k &= x[i];
	}
	return k;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n)
		cin >> op[i] >> x[i];

	forn (i, 10) {
		int a = f(1 << i) & (1 << i);
		int b = f(0) & (1 << i);

		if (a && !b) {
			res[1] |= (1 << i);
		} else if (!a && b) {
			res[1] |= (1 << i);
			res[2] |= (1 << i);
		} else if (a && b) {
			res[0] |= (1 << i);
			res[1] |= (1 << i);
		}
	}

	cout << 3 << endl;
	cout << "| " << res[0] << endl;
	cout << "& " << res[1] << endl;
	cout << "^ " << res[2] << endl;

	return 0;
}