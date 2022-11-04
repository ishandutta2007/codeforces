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

int n, m, k, x, y;
stack<ii> can;
int res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n+m && k; i++) {
		for (int j = 0; j < n+m && k; j++) {
			x = i-j;
			y = j+1;
			if (x > 0 && x <= n && y > 0 && y <= m) {
				can.emplace(x, y);
				k--;
				res += x + y - 1;
			}
		}
	}

	cout << res << endl;
	while (can.size()) {
		x = can.top().fi, y = can.top().se;
		can.pop();
		int i = 1, j = 1;
		cout << "(" << i << "," << j << ") ";
		while (i < x) {
			i++;
			cout << "(" << i << "," << j << ") ";
		}
		while (j < y) {
			j++;
			cout << "(" << i << "," << j << ") ";
		}
		cout << endl;
	}

	return 0;
}