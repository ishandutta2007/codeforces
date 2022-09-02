#include <iostream>
using namespace std;

const int N = 700;
bool dp[N][N][2];
bool edge[N][N];
int vals[N];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> vals[i];
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			if (gcd(vals[a], vals[b]) > 1) {
				edge[a][b] = true;
				// cout << "edge[" << a << "][" << b << "] = true\n";
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		dp[i][i][0] = true;
		dp[i][i][1] = true;
	}
	for (int len = 1; len < n; ++len) {
		for (int a = 0; a + len < n; ++a) {
			int b = a + len;
			for (int i = a; i < b; ++i) {
				if (dp[a][i][1] && dp[i][b-1][0] && edge[i][b]) {
					dp[a][b][1] = true;
					break;
				}
			}
			for (int i = a+1; i <= b; ++i) {
				if (dp[a+1][i][1] && dp[i][b][0] && edge[i][a]) {
					dp[a][b][0] = true;
					break;
				}
			}
		}
	}
	
	bool can = false;
	for (int i = 0; i < n; ++i) {
		if (dp[0][i][1] && dp[i][n-1][0]) can = true;
	}
	if (can) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}