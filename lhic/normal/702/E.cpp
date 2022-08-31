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

const int LOG = 40;
const int MAXN = 101000;

int n;
int p[MAXN];
int w[MAXN];
int go[LOG][MAXN];
ll sm[LOG][MAXN];
ll mn[LOG][MAXN];

ll k;

int main() {
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", p + i);
	for (int i = 0; i < n; ++i)
		scanf("%d", w + i);
	for (int i = 0; i < n; ++i) {
		go[0][i] = p[i];
		sm[0][i] = w[i];
		mn[0][i] = w[i];
	}
	for (int i = 1; i < LOG; ++i) {
		for (int j = 0; j < n; ++j) {
			go[i][j] = go[i - 1][go[i - 1][j]];
			sm[i][j] = sm[i - 1][j] + sm[i - 1][go[i - 1][j]];
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][go[i - 1][j]]);
		}
	}
	for (int i = 0; i < n; ++i) {
		ll mni = 1e9;
		ll sum = 0;
		ll nk = k;
		int now = i;
		for (int j = LOG - 1; j >= 0; --j) {
			if ((1ll << j) <= nk) {
				nk -= (1ll << j);
				sum += sm[j][now];
				mni = min(mni, mn[j][now]);
				now = go[j][now];
			}
		}
		printf("%lld %lld\n", sum, mni);
	}
	return 0;
}