#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, d, a, b, mx = 0, mn = 0;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			if (i * 2 < n) a++;
			else b++;
		} else {
			if (i * 2 < n) d += s[i] -'0';
			else d -= s[i] - '0';
		}
	}

	int x = a, y = b;
	while (a || b) {
		if (a) mx += 9, a--;
		else b--;
		if (b) mx -= 9, b--;
		else a--;	
	}

	a = x, b = y;
	while (a || b) {
		if (b) mn -= 9, b--;
		else a--;
		if (a) mn += 9, a--;
		else b--;
	}

	if (d + mx == 0 && d + mn == 0) cout << "Bicarp" << endl;
	else cout << "Monocarp" << endl;

	return 0;
}