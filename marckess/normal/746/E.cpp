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

	int n, m, a, b[200005], res = 0, c[] = {0, 0};
	set<int> ex;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;

		if (ex.find(a) == ex.end()){
			ex.insert(a);
			b[i] = a;

			c[a%2]++;
		} else {
			res++;
			b[i] = -1;
		}
	}

	for (int l = 0; l < 2; l++) {
		if (c[l] > n / 2) {
			res += c[l] - n / 2;
			for (int i = 0; i < n; i++) {
				if (b[i] > -1 && b[i] % 2 == l && c[l] > n / 2) {
					b[i] = -1;
					c[l]--;
				}
			}
		}
	}

	int np = 2, ni = 1;
	while (ex.find(np) != ex.end())
		np += 2;
	while (ex.find(ni) != ex.end())
		ni += 2;

	for (int i = 0; i < n; i++) {
		if (b[i] == -1) {
			if (c[0] < n / 2) {
				if (np > m) {
					cout << -1 << endl;
					return 0;
				}
				b[i] = np;
				
				np += 2;
				while (ex.find(np) != ex.end())
					np += 2;
				c[0]++;
			} else {
				if (ni > m) {
					cout << -1 << endl;
					return 0;
				}
				b[i] = ni;
				
				ni += 2;
				while (ex.find(ni) != ex.end())
					ni += 2;
				c[1]++;
			}
		}
	}

	cout << res << endl;
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;

	return 0;
}