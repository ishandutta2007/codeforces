#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
constexpr int inf = 1'000'000'000;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int l, n;
	cin >> l >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<int> al(n), ar(n); //left range
	auto in = [&](int x, int L, int R) {
		return (x >= L) and (x <= R);
	};

	auto ck = [&](int L, int R) {
		al[0] = ar[0] = 0;
		for (int i = 1; i < n; i += 1) {
			al[i] = al[i - 1] + L;
			ar[i] = ar[i - 1] + R;
			if (al[i] < a[i - 1]) al[i] = a[i - 1];
			if (ar[i] > a[i]) ar[i] = a[i];
			if (al[i] > ar[i]) return 0;
		}
		if (in(l, al[n - 1] + L, ar[n - 1] + R)) return 1;
		return 0;
	};

	auto F = [&](int L, int R, int flag) {
		int ret = -1;
		while(L <= R) {
			int mid = (L + R) >> 1;
			if (!flag) {
				if (ck(mid, inf)) {
					ret = mid;
					L = mid + 1;
				} else {
					R = mid - 1;
				}
			} else {
				if (ck(0, mid)) {
					ret = mid;
					R = mid - 1;
				} else {
					L = mid + 1;
				}
			}
		}
		return ret;
	};
	int LL = F(0, inf, 0), RR = F(0, inf, 1);

	vector<int> ans(n + 1);
	ans[n] = l;
	assert(ck(LL, RR) == 1);
	for (int i = n - 1; i >= 1; i -= 1) {
		ans[i] = ar[i];
		if (ans[i + 1] - ans[i] <= LL) {
			ans[i] = ans[i + 1] - LL;
		}
	}
	ans[0] = 0;	
	for (int i = 0; i < n; i += 1) {
	 	assert(in(a[i], ans[i], ans[i + 1]));
		assert(in(ans[i + 1] - ans[i], LL, RR));
		cout << ans[i] << ' ' << ans[i + 1] << '\n';
	}
}