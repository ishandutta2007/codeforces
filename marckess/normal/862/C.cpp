#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
#define MOD(n,k) ((((n) % (k)) + (k)) % (k))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, tm, x, res[100005], mk = (1 << 19) - 1;

	cin >> n >> x;

	tm = n;
	res[0] = x;
	n--;

	if (x == 0) {

		if (n % 4 == 1) {
			if (tm == 2) {
				cout << "NO" << endl;
				return 0;
			}

			res[0] = mk ^ 1;
			res[n] = mk ^ 2;
			res[n-1] = mk ^ 4;
			res[n-2] = 7;
			n -= 3;
			x = 7;

		} else if (n % 4 == 2) {
			res[0] = mk;
		} else if (n % 4 == 3) {
			res[n] = mk;
			n -= 1;
		}

	} else {

		if (n % 4 == 1) {
			res[n] = 0;
			n -= 1;
		} else if (n % 4 == 2) {
			res[0] ^= mk;
			res[n] = 0;
			res[n-1] = mk;
			n -= 2;
		} else if (n % 4 == 3) {
			res[n] = mk;
			n -= 1;
		}

	}

	for (int i = 1, j = 1; i <= n; i += 2, j++) {
		while (x == j  || j == 1 || j == 2 || j == 4)
			j++;

		res[i] = j;
		res[i+1] = mk ^ j;
	}

	ll acu = 0;
	cout << "YES" << endl;
	bitset<1000005> bs;
	for (int i = 0; i < tm; i++) {
		cout << res[i] << " ";
		acu ^= res[i];
		if (bs[res[i]] || res[i] > 1000000) {
			cout << -1 << endl;
			return -1;
		}
		bs[res[i]] = 1;
	}
	cout << endl;
	//cout << acu << endl;

	return 0;
}