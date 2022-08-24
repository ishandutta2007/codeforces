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

deque<tuple<ll, ll, int> > dd;
ll ans[240000];
int n, b;
vector<tuple<ll, ll, int> > vv;

int main() {
	scanf("%d%d", &n, &b);
	++b;
	for (int i = 0; i < n; ++i) {
		ll t, d;
		scanf("%lld%lld", &t, &d);
		vv.push_back(make_tuple(t, d, i));
	}
	ll now = 0;
	for (int i = 0; i < n; ++i) {
		while (!dd.empty() && max(now, get<0>(dd.front())) + get<1>(dd.front()) <= get<0>(vv[i])) {
			ans[get<2>(dd.front())] = max(now, get<0>(dd.front())) + get<1>(dd.front());
			now = ans[get<2>(dd.front())];
			dd.pop_front();
		}
		if ((int)dd.size() >= b)
			ans[get<2>(vv[i])] = -1;
		else
			dd.push_back(vv[i]);
	}
	while (!dd.empty()) {
		ll t, d;
		int x;
		tie(t, d, x) = dd.front();
		dd.pop_front();
		ans[x] = max(now, t) + d;
		now = ans[x];
	}
	for (int i = 0; i < n; ++i)
		printf("%lld ", ans[i]);
	printf("\n");

	return 0;
}