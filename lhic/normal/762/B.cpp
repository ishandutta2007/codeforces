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

int a, b, c;
int m;
vector<ll> vv[2];
char buf[100];

int main() {
	scanf("%d%d%d", &a, &b, &c);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int x;
		scanf("%d %s", &x, buf);
		if (buf[0] == 'U')
			vv[0].push_back(x);
		else
			vv[1].push_back(x);
	}
	int ans = 0;
	ll cs = 0;
	sort(vv[0].begin(), vv[0].end());
	sort(vv[1].begin(), vv[1].end());
	for (int i = 0; i < (int)vv[0].size() - 1; ++i)
		vv[0][i + 1] += vv[0][i];
	for (int i = 0; i < (int)vv[1].size() - 1; ++i)
		vv[1][i + 1] += vv[1][i];
	for (int i = 0; i <= min(a + c, (int)vv[0].size()); ++i) {
		int x = b + min(c, a + c - i);
		x = min(x, (int)vv[1].size());
		ll c = 0;
		if (i != 0)
			c += vv[0][i - 1];
		if (x != 0)
			c += vv[1][x - 1];
		if (x + i > ans || (x + i == ans && c < cs))
			ans = x + i, cs = c;
	}
	cout << ans << " " << cs << "\n";
	return 0;
}