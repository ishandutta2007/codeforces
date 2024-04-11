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

ll n, m, s, d;
vector<ll> vv;
vector<pair<int, ll> > ans;

int main() {
	scanf("%lld%lld%lld%lld", &n, &m, &s, &d);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		vv.push_back(a);
	}
	vv.push_back(-1);
	sort(vv.begin(), vv.end());
	ll lst = vv.back() + 1;
	if (lst != m)
		ans.push_back(make_pair(0, m - lst));
	for (int i = (int)vv.size() - 2; i >= 0; --i) {
		ll go = vv[i] + 1;
		ll nx = vv[i + 1] - 1;
		if (nx - go < s)
			continue;
		if (lst - nx > d)
			continue;
		ans.push_back(make_pair(1, lst - nx));
		ans.push_back(make_pair(0, nx - go));
		lst = go;
	}
	if (lst != 0) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < (int)ans.size(); ++i) {
			if (ans[i].first == 0)
				printf("RUN %lld\n", ans[i].second);
			else
				printf("JUMP %lld\n", ans[i].second);
		}
	}
	return 0;
}