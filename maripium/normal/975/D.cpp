#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int INF = 4e9;
int n, a, b;
vector<pair<int,int> > vct;
signed main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b;
	for (int i = 0;i < n;++i) {
		int x, vx, vy; cin >> x >> vx >> vy;
		vct.pb(mp(vy - vx * a, vx));
	}
	
	sort(vct.begin(), vct.end());
	int res = 0;
	for (int i = 0;i < n;++i) {
		int add = lower_bound(vct.begin(), vct.end(), mp(vct[i].fi + 1, -INF)) - lower_bound(vct.begin(), vct.end(), mp(vct[i].fi, -INF));
		int sub = upper_bound(vct.begin(), vct.end(), vct[i]) - lower_bound(vct.begin(), vct.end(), vct[i]);
		res += add - sub;
	}
	cout << res << endl;
}