#pragma optimize("-O3")
#include <bits/stdc++.h>
 
using namespace std;

using ll = long long;
const int mod = 998244353;
const ll mod2 = (ll) mod * mod;

int toId(char c) {
	if ('a' <= c && c <= 'z') {
		return c - 'a';
	} else if ('A' <= c && c <= 'Z') {
		return 26 + c - 'A';
	} else {
		return 52 + c - '0';
	}
}
 
ll solve(vector<string> &words) {
	sort(words.begin(), words.end());
	words.resize(unique(words.begin(), words.end()) - words.begin());
	int cnt[62][62]{};
	for (auto s : words) {
		int u = toId(s[0]);
		int v = toId(s.back());
		cnt[u][v]++;
	}
	ll f[62][62][62]{};
	for (int x = 0; x < 62; ++x) {
		for (int y = x; y < 62; ++y) {
			for (int z = y; z < 62; ++z) {
				for (int t = 0; t < 62; ++t) {
				   ll coef = (ll) cnt[x][t] * cnt[y][t] % mod;
					f[x][y][z] += coef * cnt[z][t];
					if (f[x][y][z] >= mod2) f[x][y][z] -= mod2;
				}
				ll cur = f[x][y][z] % mod;
				f[x][y][z] = f[x][z][y] = f[y][x][z] = f[y][z][x] = f[z][x][y] = f[z][y][x] = cur;
			}
		}
	}
	ll ans = 0;
	for (int x = 0; x < 62; ++x) {
		for (int y = 0; y < 62; ++y) {
			for (int z = 0; z < 62; ++z) {
			   ll coef = f[x][y][z];
			   ll now = 0;
				for (int t = 0; t < 62; ++t) {
				   now += (f[x][y][t] * f[y][z][t] % mod * f[x][z][t]);
					if (now >= mod2) {
					   now -= mod2;
					}
				}
				now %= mod;
				ans += coef * now;
				if (ans >= mod2) {
				   ans -= mod2;
				}
			}
		}
	}
	ans %= mod;
	return ans;
}
 
vector<string> words[15];

int main() {
	// ios_base::sync_with_stdio(false);
	int n;
	scanf("%d", &n);
	while (n--) {
		char s[10];
		scanf("%s", s);
		int ln = strlen(s);
		string ss(s, s + ln);
		words[ln].push_back(ss);
		words[ln].push_back(string(ss.rbegin(), ss.rend()));
	}	
	ll ans = 0;
	for (int i = 3; i <= 10; ++i) {
		// if (words[i].size()) {
			ans += solve(words[i]);
		// }
	}
	printf("%lld\n", ans % mod);
	return 0;
}