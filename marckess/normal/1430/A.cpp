#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 1010;
int pos[MX];

void solve () {
	int n, a = 0, b = 0, c = 0;
	cin >> n;
	
	if (!pos[n]) {
		cout << - 1 << endl;
		return;
	}
	
	while (n) {
		if (pos[n - 3]) a++, n -= 3;
		else if (pos[n - 5]) b++, n -= 5;
		else c++, n -= 7;
	}
	
	cout << a << " " << b << " " << c << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	pos[0] = 1;
	forn (i, 1001) {
		pos[i + 3] |= pos[i];
		pos[i + 5] |= pos[i];
		pos[i + 7] |= pos[i];
	}
	
	int t;
	cin >> t;
	while (t--)
		solve();	
	
	return 0;
}