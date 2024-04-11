#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1e16;
const int N = 5000 + 10;
const int K = N/2;

ll dp[3][K+1][3];
int ai[N+2];

void print(ll v) {
	if (v >= INF) cout << "INF ";
	else cout << v << ' ';
}

int main() {
	int n;
	cin >> n;
	ai[0] = 0;
	ai[1] = 0;
	for (int i = 2; i <= n+1; ++i) cin >> ai[i];

	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k <= (n+1)/2; ++k) {
			for (int j = 0; j < 3; ++j) {
				dp[i][k][j] = INF;
			}
		}
	}

	dp[1][0][0] = 0;
	for (int j = 2; j <= n+1; ++j) {
		int i = j % 3;
		int pi = (i+2)%3;
		for (int k = 0; k <= j/2; ++k) {
			// This is, previous isn't
			if (k > 0) {
				ll off1 = dp[pi][k-1][1] + max(0, min(ai[j-1],ai[j-2]-1) - (ai[j]-1));
				ll off2 = dp[pi][k-1][0] + max(0, 1+ai[j-1]-ai[j]);
				dp[i][k][2] = min(off1, off2);
			}
			// This isn't, previous is
			dp[i][k][1] = dp[pi][k][2] + max(0, 1+ai[j]-ai[j-1]);
			// This isn't, previous isn't
			dp[i][k][0] = min(dp[pi][k][1], dp[pi][k][0]);
			
			/*
			cout << j << ' ' << k << ": ";
			print(dp[i][k][0]);
			print(dp[i][k][1]);
			print(dp[i][k][2]);
			cout << '\n';
			*/
		}
	}
	int li = (n+1)%3;
	for (int k = 1; k <= (n+1)/2; ++k) {
		cout << min(min(dp[li][k][0], dp[li][k][1]), dp[li][k][2]) << ' ';
	}
	cout << '\n';
}