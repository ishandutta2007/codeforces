#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define SZ(x) ((int)x.size())
#define DB(x) cout << #x << "=" << x << endl
//#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double EPS = 1e-7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 10;

int64 A, B, n;

int64 solve(int64 l, int64 m, int64 k){
	int64 ans = A + (l + k - 1) * B;
	int64 val = (k + 1) * (A + (l - 1) * B) + k * (k + 1) * B / 2;
	ans = max(ans, (val + m - 1) / m);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> n;
	for (int i = 0; i < n; ++i){
		int64 l, t, m;
		cin >> l >> t >> m;

		if (solve(l, m, 0) > t){
			cout << -1 << endl;
			continue;
		}

		int64 lo = 0, hi = 1;
		while (solve(l, m, hi) <= t) hi *= 2;
		while (lo + 1 < hi){
			int mid = (lo + hi) >> 1;
			if (solve(l, m, mid) <= t) lo = mid;
			else hi = mid;
		}
		cout << l + lo << endl;
	}

	return 0;
}