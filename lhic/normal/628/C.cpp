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
const int MAXN = 300000;

int n, k;
char s[MAXN];
char ans[MAXN];

int main() {
	scanf("%d%d", &n, &k);
	scanf(" %s", s);
	int go = 0;
	for (int i = 0; i < n; ++i) {
		go += max(s[i] - 'a', 'z' - s[i]);
	}
	if (go < k) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] - 'a' > 'z' - s[i]) {
			if (s[i] - k >= 'a')
				ans[i] = s[i] - k;
			else
				ans[i] = 'a';
			k -= min(k, s[i] - 'a');
		}
		else {
			if (s[i] + k <= 'z')
				ans[i] = s[i] + k;
			else
				ans[i] = 'z';
			k -= min(k, 'z' - s[i]);
		}
	}
	printf("%s\n", ans);
	return 0;
}