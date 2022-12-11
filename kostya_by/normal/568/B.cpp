#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 4004;
const int MOD = 1000000007;

int s[MAXN][MAXN];

void solve() {
	int n; cin >> n;

	s[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			s[i][j] = (s[i - 1][j - 1] + j * 1ll * s[i - 1][j] ) % MOD;
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer += (i * 1ll * s[n][i] ) % MOD;
		answer %= MOD;
	}

	cout << answer << "\n";
}

int main() {

	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}