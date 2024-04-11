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

int n;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	if (n & 1) {
		cout << 1 + (n - 3) / 2 << endl;
		cout << 3;
		n -= 3;
		while (n) {
			cout << " " << 2;
			n -= 2;
		}
		cout << endl;
	} else {
		cout << n / 2 << endl;
		while (n) {
			cout << 2 << " ";
			n -= 2;
		}
		cout << endl;
	}

	return 0;
}