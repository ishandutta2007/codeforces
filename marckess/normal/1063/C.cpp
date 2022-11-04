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

int query (int x, int y) {
	string s;
	cout << x << " " << y << endl;
	fflush(stdout);
	cin >> s;
	return s[0] == 'b';
}

void ans (int x1, int y1, int x2, int y2) {
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	fflush(stdout);
}

int n, f = -1, x = 0;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	while (n) {
		n--;
		int a = query(x, 0);
		
		if (f == -1) {
			f = a;
			x += 2;
		} else if (a == f) {
			x += 2;
		} else {
			x--;
			break;
		}
	}

	if (!n) {
		ans(x, 0, x, 1);
		return 0;
	}

	int i = x, j = 1e9;
	while (n) {
		n--;
		int m = (i+j)/2;
		if (query(m, 1) == f) i = m;
		else j = m;
	}

	ans(x, 0, (i+j)/2, 1);

	return 0;
}