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

int num (int n) {
	int res = 0;
	while (n) {
		res += n / 5;
		n /= 5;
	}
	return res;
}

int m;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> m;
	for (int i = 0; i <= 5 * m; i += 5)
		if (num(i) == m) {
			cout << "5" << endl;
			for (int j = 0; j < 5; j++)
				cout << i+j << " ";
			cout << endl;
			return 0;
		}

	cout << 0 << endl;

	return 0;
}