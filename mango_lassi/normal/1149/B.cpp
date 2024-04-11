#include <iostream>
#include <vector>
using namespace std;

const int C = 1 + 26;
const int M = 1 + 250;
const int N = 1 + (int)1e5;
int dp[M+1][M+1][M+1];
int nxt[C][N+2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	string str;
	cin >> str;

	// nxt[c][k]: say we have used the first k characters, and want to use characters up to the next occurrence of c.
	// Up to where should we use characters? If c doesn't occur afterwards, this is set to n+1.
	for (int c = 0; c < 26; ++c) {
		nxt[c][n+1] = n+1;
		nxt[c][n] = n+1;
	}
	for (int i = n-1; i >= 0; --i) {
		for (int c = 0; c < 26; ++c) {
			nxt[c][i] = nxt[c][i+1];
		}
		nxt[str[i] - 'a'][i] = i+1;
	}

	// DP state: If we have the first A characters of first religion, B characters of second religion,
	// and C characters of third religion, where are we on the string.

	dp[0][0][0] = 0;
	vector<string> rels(3);

	for (int j = 0; j < q; ++j) {
		char op;
		cin >> op;
		if (op == '+') {
			int i;
			cin >> i;
			--i;

			char ch;
			cin >> ch;
			rels[i].push_back(ch);

			for (int a = (i == 0 ? rels[0].size() : 0); a <= (int)rels[0].size(); ++a) {
				for (int b = (i == 1 ? rels[1].size() : 0); b <= (int)rels[1].size(); ++b) {
					for (int c = (i == 2 ? rels[2].size() : 0); c <= (int)rels[2].size(); ++c) {
						dp[a][b][c] = n+1; // Not yet reached state, so we reset it
						if (a > 0) {
							int ahi = (rels[0][a-1] - 'a');
							dp[a][b][c] = min(dp[a][b][c], nxt[ahi][dp[a-1][b][c]]);
						}
						if (b > 0) {
							int bhi = (rels[1][b-1] - 'a');
							dp[a][b][c] = min(dp[a][b][c], nxt[bhi][dp[a][b-1][c]]);
						}
						if (c > 0) {
							int chi = (rels[2][c-1] - 'a');
							dp[a][b][c] = min(dp[a][b][c], nxt[chi][dp[a][b][c-1]]);
						}
					}
				}
			}
		} else {
			int i;
			cin >> i;
			--i;

			rels[i].pop_back();
		}
		if (dp[rels[0].size()][rels[1].size()][rels[2].size()] <= n) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}