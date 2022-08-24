#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

struct st {
	ll x, c, d;
	st(ll X, ll C, ll D) {
		x = X, c = C, d = D;
	}
	st() {
		x = c = d = 0;
	}
};
const int MAXN = 210000;

deque<st> dd;
ll d, n;
int m;

pair<ll, ll> arr[MAXN];

int main() {
	scanf("%lld%lld%d", &d, &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%lld%lld", &arr[i].first, &arr[i].second);
	sort(arr, arr + m);
	if (n >= d) {
		cout << 0 << "\n";
		return 0;
	}
	arr[m] = make_pair(d, 0);
	for (int i = 0; i < m; ++i)
		if (arr[i + 1].first - arr[i].first > n) {
			cout << -1 << "\n";
			return 0;
		}
	if (m == 0 || arr[0].first > n) {
		cout << -1 << "\n";
		return 0;
	}
	ll now = 0;
	dd.push_back(st(0, 0, 0));
	ll mx = n;
	for (int i = 0; i <= m; ++i) {
		now = arr[i].first;
		st pr = st(-1, -1, -1);
		while (!dd.empty() && dd.front().x < now)
			pr = dd.front(), dd.pop_front();
		if (dd.empty() || dd.front().x != now) {
			st xx;
			xx.x = now;
			xx.d = pr.d;
			xx.c = pr.c + pr.d * (now - pr.x);
			dd.push_front(xx);
		}
		ll lst = mx;
		ll lstm = dd.back().c + dd.back().d * (lst - dd.back().x);
		while (!dd.empty() && dd.back().d > arr[i].second) {
			lst = min(lst, dd.back().x);
			lstm = dd.back().c;
			dd.pop_back();
		}
		dd.push_back(st(lst, lstm, arr[i].second));
		mx = now + n;
	}
	cout << dd.front().c << "\n";
	return 0;
}