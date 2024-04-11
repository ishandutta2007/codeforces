#include <bits/stdc++.h>
//#define endl '\n'
using namespace std;
#define int long long
const int N = 1e3 + 10, M = N * N;
int n, se;
char ans[N], x;
#define all(a) a.begin(),a.end()
char ask1(int i) {
	cout << "? 1 " << i << endl;
	cin >> x;
	return x;
}
int ask2(int l, int r) {
	cout << "? 2 " << l << " " << r << endl;
	cin >> se;
	return se;
}
void solve() {

	cin >> n;
	int now = 0;
	for (int i = 1; i <= n; i++) {
		int t = ask2(1, i);
		if (t != now) {
			now = t;
			ans[i] = ask1(i);
		}
	}
	vector<int> last(27);
	for (int i = 1; i <= n; i++) {
		if (!ans[i]) {
			vector<int> res;
			for (int j = 1; j <= 26; j++) if (last[j]) res.push_back(j);

			sort(all(res), [&](int x, int y) {
				return last[x] < last[y];
			});

			int sz = res.size();
			int l = 0, r = sz - 1;
			while (l <= r) {
				int mid = l + r >> 1;
				if (ask2(last[res[mid]], i) + mid == sz) l = mid + 1;
				else r = mid - 1;
			}
			ans[i] = (char)(res[l - 1] - 1 + 'a');
		}
		last[ans[i] - 'a' + 1] = i;
	}
	cout << "! ";
	for (int i = 1; i <= n; i++) cout << ans[i];
}
signed main() {

//	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
//	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}