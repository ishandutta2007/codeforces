#include<bits/stdc++.h>
using namespace std;

int A[500][500];
int lo[10] = {}, hi[10] = {};
int f0[10][500], f1[10][500];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];

	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < n; i++) {
			f1[k][i] = f0[k][i] = -1;
			for (int j = 0; j < m; j++) {
				if ((A[i][j] >> k) & 1) {
					hi[k]++; f1[k][i] = j; break;
				}
			}
			lo[k]++;
			for (int j = 0; j < m; j++) {
				if (~(A[i][j] >> k) & 1) {
					lo[k]--; f0[k][i] = j; break;
				}
			}
		}
	}

	for (int k = 0; k < 10; k++) {
		int targ = lo[k] + (~lo[k] & 1);
		if (targ > hi[k])
			continue;

		cout << "TAK\n";
		vector<int> r(n, -1);
		for (int i = 0; i < n; i++) {
			if (f0[k][i] < 0) r[i] = f1[k][i], targ--;
			else if (f1[k][i] < 0) r[i] = f0[k][i];
		}
		for (int i = 0; i < n; i++) {
			if (r[i] >= 0) continue;
			assert(f0[k][i] >= 0 && f1[k][i] >= 0);
			if (targ > 0) r[i] = f1[k][i], targ--;
			else r[i] = f0[k][i];
		}
		for (int i = 0; i < n; i++) {
			cout << (r[i] + 1) << ' ';
		}
		cout << endl;
		return 0;
	}

	cout << "NIE\n";
	return 0;
}