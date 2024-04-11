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

const int MAXN = 101000;
const ll MOD = 1000000007;

int m;
char s[MAXN];
int len;
map<pair<int, int>, ll> mm;
vector<int> go[MAXN];
vector<pair<int, int> > qq;
ll pw25[MAXN];
ll fc[MAXN];
ll bfc[MAXN];

ll pw(ll a, ll b) {
	ll ans = 1;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = (a * a) % MOD;
		--b;
		ans = (ans * a) % MOD;
	}
	return ans;
}



ll cnk(int n, int k) {
	if (n < k)
		return 0;
	ll ans = (fc[n] * bfc[k]) % MOD;
	ans = (ans * bfc[n - k]) % MOD;
	return ans;
}

void init() {
	pw25[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		pw25[i] = (pw25[i - 1] * 25) % MOD;
	fc[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	for (int i = 0; i < MAXN; ++i)
		bfc[i] = pw(fc[i], MOD - 2);
}



int main() {
	init();
	scanf("%d", &m);
	scanf(" %s", s);
	len = strlen(s);
	for (int i = 0; i < m; ++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			scanf(" %s", s);
			len = strlen(s);
		}
		else {
			int n;
			scanf("%d", &n);
			go[len].push_back(n);
			qq.push_back(make_pair(len, n));
		}
	}
	for (int i = 0; i < MAXN; ++i) {
		if (!go[i].empty()) {
			sort(go[i].begin(), go[i].end());
			go[i].resize(unique(go[i].begin(), go[i].end()) - go[i].begin());
			int now = 0;
			while (now < (int)go[i].size() && go[i][now] < i)
				mm[make_pair(i, go[i][now])] = 0, ++now;
			ll ans = 0;
			for (int j = i; now < (int)go[i].size(); ++j) {
				ans = (ans * 26) % MOD;
				ll gg = (pw25[j - i] * cnk(j - 1, i - 1)) % MOD;
				ans += gg;
				if (ans >= MOD)
					ans -= MOD;
				while (now < (int)go[i].size() && go[i][now] == j)
					++now, mm[make_pair(i, j)] = ans;
			}
		}
	}
	for (int i = 0; i < (int)qq.size(); ++i) {
		printf("%d\n", (int)mm[qq[i]]);
	}
	return 0;
}