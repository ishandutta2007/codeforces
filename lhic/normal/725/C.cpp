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

string s;
char ans[2][20];

int main() {
	cin >> s;
	for (int i = 0; i < 27; ++i)
		for (int j = i + 1; j < 27; ++j) {
			if (s[i] != s[j])
				continue;
			if (j == i + 1) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			if ((j - i) % 2 == 0) {
				int d = (j - i) / 2 - 1;
				ans[1][d] = s[i];
				for (int k = i + 1; k <= i + d + 1; ++k)
					ans[0][d + (i + 1 - k)] = s[k];
				for (int k = i + d + 2; k < j; ++k)
					ans[1][k - (i + d + 2)] = s[k];
				string s2 = s.substr(0, i);
				string s3 = s.substr(j + 1);
				reverse(s2.begin(), s2.end());
				reverse(s3.begin(), s3.end());
				s2 = s2 + s3;
				for (int k = d + 1; k < 13; ++k)
					ans[0][k] = s2[k - d - 1];
				int st = 13 - d - 1;
				for (int k = 12; k > d; --k)
					ans[1][k] = s2[st + (12 - k)];
				cout << ans[0] << "\n";
				cout << ans[1] << "\n";
				return 0;
			}
			else {
				int d = (j - i) / 2;
				ans[1][d] = s[i];
				for (int k = i + 1; k <= i + d; ++k)
					ans[0][d - 1 + (i + 1 - k)] = s[k];
				for (int k = i + d + 1; k < j; ++k)
					ans[1][k - (i + d + 1)] = s[k];
				string s2 = s.substr(0, i);
				string s3 = s.substr(j + 1);
				reverse(s2.begin(), s2.end());
				reverse(s3.begin(), s3.end());
				s2 = s2 + s3;
				for (int k = d; k < 13; ++k)
					ans[0][k] = s2[k - d];
				int st = 13 - d;
				for (int k = 12; k > d; --k)
					ans[1][k] = s2[st + (12 - k)];
				cout << ans[0] << "\n";
				cout << ans[1] << "\n";
				return 0;
			}
		}
	assert(false);
	return 0;
}