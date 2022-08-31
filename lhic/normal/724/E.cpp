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
const int MAXN = 12000;

ll dp[MAXN];
int n;
ll c;
ll p[MAXN];
ll s[MAXN];

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i) {
		dp[i + 1] = dp[i] + s[i];
		for (int j = i; j > 0; --j) {
			dp[j] += p[i] + c * j;
			dp[j] = min(dp[j], dp[j - 1] + s[i]);
		}
		dp[0] += p[i];
	}
	ll mn = dp[0];
	for (int i = 0; i <= n; ++i)
		mn = min(mn, dp[i]);
	cout << mn << "\n";
	return 0;
}