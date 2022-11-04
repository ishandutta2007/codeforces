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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

string a, b;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int in;
	forn (i, 4) {
		char c;
		cin >> c;
		a.pb(c);
	}
	swap(a[2], a[3]);
	
	forn (i, 4) {
		if (a[i] == 'X') in = i;
	}
	a.erase(a.begin() + in);

	forn (i, 4) {
		char c;
		cin >> c;
		b.pb(c);
		if (c == 'X') in = i;
	}
	swap(b[2], b[3]);

	forn (i, 4) {
		if (b[i] == 'X') in = i;
	}
	b.erase(b.begin() + in);

	forn (i, 3) {
		if (a == b) {
			cout << "YES" << endl;
			return 0;
		}
		a.pb(*a.begin());
		a.erase(a.begin());
	}

	cout << "NO" << endl;
	
	return 0;
}