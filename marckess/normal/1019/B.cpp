#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n;

int w (char c, int x) {
	int y;
	cout << c << " " << x << endl;
	fflush(stdout);
	if (c == '?') cin >> y;
	return y;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	if ((n / 2) % 2) {
		w('!', -1);
		return 0;
	}

	if (n <= 60) {
		for (int i = 1; i <= n / 2; i++)
			if (w('?', i) == w('?', i+n/2)) {
				w('!', i);
				return 0;
			}
		w('!', -1);
		return 0;
	}

	int i = 1, j = n / 2 + 1, rep = 20;
	int a = w('?', i);
	int b = w('?', j);
	if (a == b) {
		w('!', a);
		return 0;
	}
	int f = a < b;

	while (rep--) {
		int m = (i+j)/2;
		int a = w('?', m);
		int b = w('?', m+n/2);
		
		if (a == b) {
			w('!', m);
			return 0;
		}

		if ((a < b) == f) i = m;
		else j = m;
	}

	w('!', -1);

	return 0;
}