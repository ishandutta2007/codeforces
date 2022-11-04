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

	int n, q, a[200005], x, y, res[200005];

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	vi ult(n+1), t(n+1);

	for (int i = 1; i <= q; i++) {
		cin >> x >> y;

		ult[y] = i;
		t[y] = x;
	}

	multiset<int> ms;
	for (int i = 1; i <= n; i++)
		ms.insert(a[i]);

	int au = 0, at = 1;
	for (int i = n; i; i--) {
		if (ult[i] > au) {
			au = ult[i];
			at = t[i];
		}

		if (au) {
			if (at == 1) {
				auto it = ms.end();
				it--;

				res[i] = *it;
				ms.erase(it);
			} else {
				auto it = ms.begin();

				res[i] = *it;
				ms.erase(it);
			}
		} else {
			res[i] = a[i];
			ms.erase(ms.find(a[i]));
		}
	}

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}