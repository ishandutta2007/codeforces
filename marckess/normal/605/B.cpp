#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m, a[100005], b[100005], q[100005];
	int u[100005], v[100005];

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		q[i] = i;
	}
	sort(q, q+m, [&] (int x, int y) {
		if (a[x] == a[y])
			return b[x] > b[y];
		return a[x] < a[y];
	});

	int top = 3, pun = 2, c = 2;
	for (int i = 0; i < m; i++) {
		int h = q[i];

		if (b[h]) {
			u[h] = 1, v[h] = c++;
		} else {
			if (top >= c) {
				cout << -1 << endl;
				return 0;
			}

			u[h] = pun, v[h] = top;
			
			pun++;
			if (pun == top) {
				pun = 2;
				top++;
			}
		}
	}

	for (int i = 0; i < m; i++)
		cout << u[i] << " " << v[i] << endl;

	return 0;
}