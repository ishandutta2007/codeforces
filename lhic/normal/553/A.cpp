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

int k;
int c[1200];
ll cnk[1200][1200];
const ll MOD = 1000000007;



ll ans = 1;

int main() {
	for (int i = 0; i < 1200; ++i)
		for (int j = 0; j < 1200; ++j) {
			if (i == j || j == 0)
				cnk[i][j] = 1;
			else if (j > i)
				cnk[i][j] = 0;
			else
				cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % MOD;
		}
	cin >> k;
	for (int i = 0; i < k; ++i)
		cin >> c[i];
	int sum = 0;
	for (int i = 0; i < k; ++i) {
		ans = (ans * cnk[sum + c[i] - 1][c[i] - 1]) % MOD;
		sum += c[i];
	}
	cout << ans;

	return 0;
}