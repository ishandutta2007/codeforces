#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int64 solve(int64 x, int64 y, int64 p, int64 q){
	if (p == 0) return x == 0 ? 0 : -1;
	if (p == q) return x == y ? 0 : -1;
	return max( (x + p - 1) / p, (y - x + q - p - 1) / (q - p)) * q - y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int t; cin >> t;
	while (t--){
		int64 x, y, p, q;
		cin >> x >> y >> p >> q;
		cout << solve(x, y, p, q) << endl;
	}

	return 0;
}