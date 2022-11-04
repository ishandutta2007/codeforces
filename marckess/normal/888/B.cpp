#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, l = 0, d = 0, r = 0, u = 0;
char c;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == 'L') l++;
		if (c == 'R') r++;
		if (c == 'U') u++;
		if (c == 'D') d++;
	}

	cout << 2 * min(l, r) + 2 * min(d, u) << endl;

	return 0;
}