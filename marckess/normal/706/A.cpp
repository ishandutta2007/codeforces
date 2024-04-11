#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define first fi;
#define second se;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ld a, b, x, y, v, res = 1e18;
	int n;

	cin >> a >> b >> n;

	while (n--) {
		cin >> x >> y >> v;
		res = min(res, hypot(a-x, b-y) / v);
	}

	cout << fixed << setprecision(8) << res << endl;

	return 0;
}