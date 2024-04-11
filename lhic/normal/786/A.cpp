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
const int MAXN = 7100;

int n;
int k1, k2;
int fr[MAXN][2];
int dp[MAXN][2];
int a[MAXN];
int b[MAXN];

void upd(int x, int y) {
	if (y == 0) {
		for (int i = 0; i < k2; ++i) {
			int tmp = x - b[i];
			if (tmp < 0)
				tmp += n;
			if (dp[tmp][1] == 0) {
				if (dp[x][y] == 1) {
					--fr[tmp][1];
					if (fr[tmp][1] == 0)
						dp[tmp][1] = 2, upd(tmp, 1);
				}
				else {
					dp[tmp][1] = 1;
					upd(tmp, 1);
				}
			}
		}
	}
	else {
		for (int i = 0; i < k1; ++i) {
			int tmp = x - a[i];
			if (tmp < 0)
				tmp += n;
			if (dp[tmp][0] == 0) {
				if (dp[x][y] == 1) {
					--fr[tmp][0];
					if (fr[tmp][0] == 0)
						dp[tmp][0] = 2, upd(tmp, 0);
				}
				else {
					dp[tmp][0] = 1;
					upd(tmp, 0);
				}
			}
		}

	}
}

int main() {
	cin >> n;
	cin >> k1;
	for (int i = 0; i < k1; ++i)
		cin >> a[i];
	cin >> k2;
	for (int i = 0; i < k2; ++i)
		cin >> b[i];
	for (int i = 1; i < n; ++i) {
		fr[i][0] = k1;
		fr[i][1] = k2;
	}
	dp[0][0] = 2;
	dp[0][1] = 2;
	upd(0, 0);
	upd(0, 1);
	for (int i = 1; i < n; ++i) {
		if (dp[i][0] == 0)
			cout << "Loop ";
		else if (dp[i][0] == 1)
			cout << "Win ";
		else
			cout << "Lose ";
	}
	cout << "\n";
	for (int i = 1; i < n; ++i) {
		if (dp[i][1] == 0)
			cout << "Loop ";
		else if (dp[i][1] == 1)
			cout << "Win ";
		else
			cout << "Lose ";
	}
	cout << "\n";
	return 0;
}