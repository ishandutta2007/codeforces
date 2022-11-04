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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, t, c, a, res = 0;
	vi v(1, -1);

	cin >> n >> t >> c;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > t)
			v.push_back(i);
	}
	v.push_back(n);

	for (int i = 1; i < v.size(); i++) {
		int d = v[i] - v[i-1] - 1;

		if (d >= c) {
			res += d - c + 1;
		}
	}
	
	cout << res << endl;

	return 0;
}