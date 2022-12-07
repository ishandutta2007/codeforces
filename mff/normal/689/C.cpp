#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int64 total(int64 n){
	int64 ans = 0;
	for (int64 i = 2; ; ++i){
		int64 v = i * i * i;
		if (v > n) break;
		ans += n / v;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 lo = 0, hi = oo;

	int64 n; cin >> n;

	while (lo + 1 < hi){
		int64 m = (lo + hi) / 2;
		if (total(m) < n) lo = m;
		else hi = m;
	}

	if (total(hi) == n) cout << hi << endl;
	else cout << -1 << endl;


	return 0;
}