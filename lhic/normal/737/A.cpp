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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 210000;

int n, k;
ll s, t;
ll c[MAXN];
ll v[MAXN];
ll b[MAXN];
vector<ll> vv;
ll pr[MAXN];

int main() {
	scanf("%d%d%lld%lld", &n, &k, &s, &t);
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", c + i, v + i);
	for (int i = 0; i < k; ++i)
		scanf("%lld", b + i);
	sort(b, b + k);
	vv.push_back(b[0] - 0);
	vv.push_back(s - b[k - 1]);
	for (int i = 0; i < k - 1; ++i)
		vv.push_back(b[i + 1] - b[i]);
	sort(vv.begin(), vv.end());
	for (int i = 0; i < (int)vv.size(); ++i)
		pr[i + 1] = pr[i] + vv[i];
	const ll INF = 2e9;
	ll ans = INF;
	for (int i = 0; i < n; ++i) {
		if (v[i] < vv.back())
			continue;
		ll x = v[i] / 2;
		int p = upper_bound(vv.begin(), vv.end(), x) - vv.begin();
		ll sum = pr[vv.size()] - pr[p];
		ll cur = pr[p] + 2 * sum - (((ll)vv.size() - p) * v[i] - sum);
		if (cur <= t)
			ans = min(ans, c[i]);
	}
	if (ans == INF)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
	return 0;
}