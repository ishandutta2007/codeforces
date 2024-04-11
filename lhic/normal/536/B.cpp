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

const int MAXN = 1000010;

int n, m, ps;

char p[MAXN];
char s[MAXN];
char s2[MAXN * 2];
int z[MAXN * 2];
int x[MAXN];
int cc;

int main() {
	scanf("%d%d", &n, &m);
	scanf(" %s", p);
	ps = strlen(p);
	for (int i = 0; i < m; ++i)
		scanf("%d", &x[i]), --x[i];
	int now = 0;
	for (int i = 0; i < n; ++i) {
		while (now < m - 1 && x[now + 1] <= i)
			++now;
		if (now < m && i >= x[now] && i - x[now] < ps)
			s[i] = p[i - x[now]];
		else
			++cc, s[i] = 0;
	}
	for (int i = 0; i < ps; ++i)
		s2[i] = p[i];
	for (int i = 0; i < n; ++i)
		s2[ps + i] = s[i];
	z[0] = 0;
	int len = ps + n;
	int l = 0;
	int r = 0;
	for (int i = 1; i < len; ++i) {
		if (r > i)
			z[i] = min(r - i, z[i - l]);
		while (i + z[i] < len && s2[z[i]] == s2[i + z[i]])
			++z[i];
		if (i + z[i] > r)
			r = i + z[i], l = i;
	}
	for (int i = 0; i < m; ++i) {
		if (z[ps + x[i]] < ps) {
			cout << 0;
			return 0;
		}
	}
	ll ans = 1;
	for (int i = 0; i < cc; ++i)
		ans = (ans * 26) % 1000000007;
	cout << ans;
	return 0;
}