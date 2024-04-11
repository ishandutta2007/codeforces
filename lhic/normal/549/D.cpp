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

ll cnt[120][120];
string s[120];
int n, m;
int ans;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = n - 1; i >= 0; --i)
		for (int j = m - 1; j >= 0; --j) {
			int nd;
			if (s[i][j] == 'B')
				nd = 1;
			else
				nd = -1;
			if (cnt[i][j] != nd) {
				++ans;
				int cc = nd - cnt[i][j];
				for (int ii = 0; ii <= i; ++ii)
					for (int jj = 0; jj <= j; ++jj)
						cnt[ii][jj] += cc;
			}
		}
	cout << ans;
	return 0;
}