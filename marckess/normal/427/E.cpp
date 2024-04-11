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

int n, m;
ll ai = 0, ci = 0, ad = 0, cd = 0, res = 1e18, p[1000005];

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &p[i]);

	for (int i = n - 1; i >= 0; i -= m) {
		ai += p[i];
		ci++;
	}

	int x = 0, y = 0;
	while (x < n) {
		while (y < n && p[x] == p[y]) {
			if (y % m == (n - 1) % m) {
				ai -= p[y];
				ci--;
			}
			y++;
		}
		y--;

		res = min(res, ai - ad + p[x] * (cd - ci));

		y++;
		while (x < y) {
			if (x % m == 0) {
				ad += p[x];
				cd++;
			}
			x++;
		}
	}

	printf("%lld\n", 2 * res);

	return 0;
}