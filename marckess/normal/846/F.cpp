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

int n, a;
vi c[1000005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);


	for (int i = 1; i <= 1e6; i++)
		c[i].push_back(-1);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		c[a].push_back(i);
	}

	ld res = 0;
	for (int i = 1; i <= 1e6; i++) {
		for (int j = 1; j < c[i].size(); j++) {
			res += 2 * ld(c[i][j] - c[i][j-1]) * ld(n - c[i][j]) - 1;
		}
	}

	res /= ld(n) * n;

	cout << fixed << setprecision(5) << res << endl;

	return 0;
}