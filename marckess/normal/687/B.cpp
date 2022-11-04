#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

bitset<1000005> bs;
vi pr;
void criba () {
	for (ll i = 2; i < 1000000; i++) {
		if (!bs[i]) {
			pr.push_back(i);
			for (ll j = i*i; j < 1000000; j += i)
				bs[j] = 1;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	criba();

	int n, k, c[1000005], es, x;
	vi dv(1e6+5);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> c[i];

	x = k;
	for (int i = 0; pr[i] * pr[i] <= x; i++) {
		dv[pr[i]] = 0;
		while (x % pr[i] == 0) {
			x /= pr[i];
			dv[pr[i]]++;
		}
	}

	if (x > 1)
		dv[x] = 1;

	for (int i = 0; i < pr.size(); i++) {
		int p = pr[i];

		if (dv[p] > 0) {
			for (int j = 0; j < n; j++) {
				int pw = 0, x = c[j];

				while (x % p == 0) {
					x /= p;
					pw++;
				}

				if (pw >= dv[p]) {
					while (k % p == 0) {
						k /= p;
					}
					break;
				}
			}
		}
	}

	if (k == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}