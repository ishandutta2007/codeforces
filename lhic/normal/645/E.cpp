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

const ll MOD = 1000000007;

ll dp[30];
int cc[30];
int cnt = 1;
char s[1200000];
int n, k;
int m;


int main() {
	scanf("%d%d", &n, &k);
	scanf(" %s", s);
	m = strlen(s);
	for (int i = 0; i < m; ++i) {
		int a = s[i] - 'a';
		ll sum = 0;
		for (int j = 0; j < k; ++j) {
			sum += dp[j];
			if (sum >= MOD)
				sum -= MOD;
		}
		sum += 1;
		if (sum >= MOD)
			sum -= MOD;
		dp[a] = sum;
		cc[a] = cnt++;
	}
	for (int i = 0; i < n; ++i) {
		ll sum = 0;
		for (int j = 0; j < k; ++j) {
			sum += dp[j];
			if (sum >= MOD)
				sum -= MOD;
		}
		sum += 1;
		if (sum >= MOD)
			sum -= MOD;
		int bst = 0;
		int bstc = cc[0];
		for (int j = 1; j < k; ++j) {
			if (cc[j] < bstc)
				bstc = cc[j], bst = j;
		}
		dp[bst] = sum;
		cc[bst] = cnt++;
	}
	ll sum = 1;
	for (int i = 0; i < k; ++i)
		sum += dp[i];
	sum %= MOD;
	cout << sum << "\n";
	return 0;
}