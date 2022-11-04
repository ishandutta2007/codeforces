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
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int s, x1, x2, t1, t2, p, d;

	cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;

	int res = abs(x1 - x2);

	int acu = 0;
	if (d == 1) {
		if (x1 >= p) {
			acu += x1 - p;
			p = x1;

			if (x2 >= p) {
				acu += x2 - p;
			} else {
				acu += 2 * s - p - x2;
			}
		} else {
			acu += 2 * s - p - x1;
			p = x1;

			if (x2 <= p) {
				acu += p - x2;
			} else {
				acu += p + x2;
			}
		}
	} else {
		if (x1 <= p) {
			acu += p - x1;
			p = x1;

			if (x2 <= p) {
				acu += p - x2;
			} else {
				acu += p + x2;
			}
		} else {
			acu += p + x1;
			p = x1;

			if (x2 >= p) {
				acu += x2 - p;
			} else {
				acu += 2 * s - p - x2;
			}
		}
	}

	cout << min(res * t2, acu * t1) << endl;

	return 0;
}