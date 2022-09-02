#include <iostream>
using namespace std;
typedef unsigned long long ll;

const ll inf = 2 * (1e18);
const int N = 40;
ll cost[N];

int main() {
	int n; ll need;
	cin >> n >> need;
	ll mp = inf;
	for (int i = 0; i < n; ++i) {
		cin >> cost[i];
		mp = min(mp * 2, cost[i]);
		cost[i] = mp;
	}
	ll res = inf;
	ll cur = 0;
	for (int i = n-1; i >= 0; --i) {
		ll siz = ((ll)1 << i);
		ll cou = need / siz;
		cur += cou * cost[i];
		need -= cou * siz;
		res = min(cur + cost[i], res);
	}
	res = min(cur, res);
	cout << res << '\n';
}