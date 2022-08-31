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
const int MAXN = 200000;
ll ans;
char s[MAXN];
int n, m;


void solve() {
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == s[i + 1])
			continue;
		ans += (m - 1) * (n - 1 - i);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	scanf(" %s", s);
	ans += (m - 1) * n;
	solve();
	reverse(s, s + n);
	solve();
	int l = 0;
	for (int i = 0; i < n; ++i) {
		l = max(l, i + 1);
		while (l < n && s[l] == s[i + (l - i) % 2] && s[i] != s[i + 1])
			++l;
		ans -= l - i - 1;
	}
	cout << ans << "\n";
	return 0;
}