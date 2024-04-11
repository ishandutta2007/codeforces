#include<bits/stdc++.h>
using namespace std;

int calc(const string &A, const string &B) {
	int n = (int) A.size();
	vector< array<int, 26> > N(n+1);
	for (int i=0; i<26; i++) N[n][i] = n;
	for (int i=n; i--; ) {
		for (int j=0; j<26; j++) N[i][j] = N[i+1][j];
		N[i][A[i] - 'a'] = i;
	}

	int ret = 1, idxB = 0, idxA = 0;
	while (idxB < (int) B.size()) {
		int nidxA = N[idxA][B[idxB] - 'a'];
		if (nidxA == n) {
			if (idxA == 0) return -1;

			// start over:
			idxA = 0;
			ret++;
		} else {
			idxA = nidxA+1;
			idxB++;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int ntc;
	cin >> ntc;
	while (ntc--) {
		string A, B;
		cin >> A >> B;
		cout << calc(A, B) << endl;
	}
	return 0;
}