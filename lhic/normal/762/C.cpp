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

string s, t;
int dp[120000];

int main() {
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	dp[m] = n;
	int now = n - 1;
	for (int i = m - 1; i >= 0; --i) {
		while (now >= 0 && s[now] != t[i])
			--now;
		dp[i] = now;
		if (now >= 0)
			--now;
	}
	now = 0;
	int len = 0;
	int l = 0;
	int r = 0;
	int now2 = 0;
	for (int i = 0; i < m; ++i) {
		now2 = max(now2, i + 1);
		while (now < n && s[now] != t[i])
			++now;
		if (now == n)
			break;
		++now;
		while (dp[now2] < now)
			++now2;
		int len2 = i + 1 + m - now2;
		if (len2 > len) {
			len = len2;
			l = i;
			r = now2;
		}
	}
	for (int i = 0; i < m; ++i)
		if (dp[i] >= 0) {
			if (m - i > len) {
				len = m - i;
				l = -1;
				r = i;
			}
		}
	if (len == 0) {
		cout << "-\n";
	}
	else {
		for (int i = 0; i <= l; ++i)
			printf("%c", t[i]);
		for (int i = r; i < m; ++i)
			printf("%c", t[i]);
		printf("\n");
	}
	return 0;
}