#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int arg1 = 1000003;
const int arg2 = 1000007;
const int Maxn = 100005;
const int Maxx = 32;

int pw1[Maxn], pw2[Maxn];
int n;
string s;
int m;
string t;
char tmp[Maxn];
int x;
ii A[Maxn], B[Maxn];
int dp[Maxn][Maxx];

void Read(string &s)
{
	scanf("%s", tmp); s = tmp;
}

ii Get(ii H[], int l, int r)
{
	ii h = H[r];
	l--;
	if (l >= 0) {
		h.first = (ll(h.first) - ll(pw1[r - l]) * H[l].first % mod1 + mod1) % mod1;
		h.second = (ll(h.second) - ll(pw2[r - l]) * H[l].second % mod2 + mod2) % mod2;
	}
	return h;
}

int Get(int a, int b)
{
	int lef = 1, rig = min(int(s.length()) - a, int(t.length()) - b);
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Get(A, a, a + mid - 1) == Get(B, b, b + mid - 1))
			lef = mid + 1;
		else rig = mid - 1;
	}
	return lef - 1;
}

int main()
{
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
		pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
	}
	scanf("%d", &n); Read(s);
	scanf("%d", &m); Read(t);
	scanf("%d", &x);
	ii h = ii(0, 0);
	for (int i = 0; i < s.length(); i++) {
		h.first = (ll(h.first) * arg1 + ll(s[i] - 'a' + 1)) % mod1;
		h.second = (ll(h.second) * arg2 + ll(s[i] - 'a' + 1)) % mod2;
		A[i] = h;
	}
	h = ii(0, 0);
	for (int i = 0; i < t.length(); i++) {
		h.first = (ll(h.first) * arg1 + ll(t[i] - 'a' + 1)) % mod1;
		h.second = (ll(h.second) * arg2 + ll(t[i] - 'a' + 1)) % mod2;
		B[i] = h;
	}
	fill((int*)dp, (int*)dp + Maxn * Maxx, -1); dp[0][0] = 0;
	for (int i = 0; i < s.length(); i++)
		for (int j = 0; j <= x; j++) if (dp[i][j] >= 0) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j < x) {
				int g = Get(i, dp[i][j]);
				if (g > 0) dp[i + g][j + 1] = max(dp[i + g][j + 1], dp[i][j] + g);
			}
		}
	bool ok = false;
	for (int j = 0; j <= x; j++)
		if (dp[s.length()][j] >= int(t.length()))
			ok = true;
	printf("%s\n", ok? "YES": "NO");
	return 0;
}