#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	int n, k, _[3] = {0};

	cin >> n;
	while (n--) {
		cin >> k;
		_[k]++;
	}

	int res = min(_[2], _[1]);
	res += (_[1] - res) / 3;

	cout << res << endl;

	return 0;
}