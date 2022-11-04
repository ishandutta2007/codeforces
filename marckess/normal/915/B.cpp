#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, pos, l, r;
	cin >> n >> pos >> l >> r;

	if (pos < l) {
		if (r != n)
			cout << r - pos + 2 << endl;
		else
			cout << l - pos + 1 << endl;
	} else if (pos > r) {
		if (l != 1)
			cout << pos - l + 2 << endl;
		else
			cout << pos - r + 1<< endl;
	} else {
		if (l == 1 && r == n)
			cout << 0 << endl;
		else if (l == 1)
			cout << r - pos + 1 << endl;
		else if (r == n)
			cout << pos - l + 1 << endl;
		else
			cout << min(r - pos, pos - l) + r - l + 2 << endl;
	}

	return 0;
}