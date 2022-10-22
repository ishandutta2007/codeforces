#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/
	int n, k, mi = 100, ma = 0, i, j, j2, mi2, ma2;
	cin >> n >> k;
	vector<int> cnt(n);
	vector<vector<int> > clr(n);
	for (i = 0; i < n; i++) {
		cin >> cnt[i];
		mi = min(mi, cnt[i]);
		ma = max(ma, cnt[i]);
	}

	for (i = 1; i <= k; i++) {
		mi2 = 100;
		ma2 = 0;
		for (j = 0; j < n; j++) {
			bool add = cnt[j] > mi;
			for (j2 = 0; j2 < (mi + add); j2++) {
				clr[j].push_back(i);
				cnt[j]--;
			}
			mi2 = min(mi2, cnt[j]);
			ma2 = max(ma2, cnt[j]);
		}
		mi = mi2;
		ma = ma2;
	}

	if (ma)
		cout << "NO";
	else {
		cout << "YES\n";
		for (i = 0; i < n; i++) {
			for (j = 0; j < clr[i].size(); j++)
				cout << clr[i][j] << ' ';
			cout << '\n';
		}
	}

	return 0;
}