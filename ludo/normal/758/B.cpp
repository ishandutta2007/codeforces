#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int col(char ch)
{
	if (ch == '!') return 0;
	if (ch == 'R') return 1;
	if (ch == 'B') return 2;
	if (ch == 'Y') return 3;
	if (ch == 'G') return 4;
	return -1;
}

int seen[4][4] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	cin >> S;

	int N = S.size();
	vector<int> c(N, 0);
	for (int i = 0; i < N; i++) {
		c[i] = col(S[i]);
		if (c[i] != 0) {
			seen[i % 4][c[i] - 1]++;
		}
	}

	int ans[4] = {};

	for (int rem = 0; rem < 4; rem++) {
		for (int i = 0; i < 4; i++) {
			cerr << seen[rem][i] << " ";
		}
		cerr << endl;
	}
	for (int rem = 0; rem < 4; rem++) {
		int nZero = 0;
		for (int i = 0; i < 4; i++) nZero += seen[rem][i] != 0;
		assert(nZero == 1);

		for (int i = 0; i < 4; i++) {
			if (seen[rem][i] == 0) continue;
			// only once
			cerr << i << ": " << N << ", " << rem << ", " << seen[rem][i] << endl;
			ans[i] = (N + 3 - rem) / 4 - seen[rem][i];
		}
	}
	for (int i = 0; i < 4; i++) {
		cout << ans[i] << " \n"[i == 3];
	}
	return 0;
}