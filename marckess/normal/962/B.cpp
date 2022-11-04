#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, a, b, f = -1, res = 0;
char c;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> a >> b;
	while (n--) {
		cin >> c;
		if (c == '*') {
			f = -1;
			continue;
		}

		if (f == -1) {
			if (a > b) {
				a--;
				res++;
				f = 0;
			} else if (b > 0) {
				b--;
				res++;
				f = 1;
			}
		} else if (f == 0) {
			if (b > 0) {
				b--;
				res++;
				f = 1;
			} else {
				f = -1;
			}
		} else {
			if (a > 0) {
				a--;
				res++;
				f = 0;
			} else {
				f = -1;
			}
		}
	}

	cout << res << endl;

	return 0;
}