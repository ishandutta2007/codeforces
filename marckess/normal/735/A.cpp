#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

int n, k, g, t;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'G')
			g = i;
		
		if (s[i] == 'T')
			t = i;
	}

	if (g > t)
		swap(g, t);

	for (int i = g; i <= t; i += k) {
		if (s[i] == '#') {
			cout << "NO";
			return 0;
		}

		if (i == t) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}