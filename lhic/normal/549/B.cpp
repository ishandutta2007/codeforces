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

int n;
string s[120];
int a[120];
int cnt[120];
vector<int> ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	bool fl = 1;
	while (fl) {
		int x = -1;
		fl = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == cnt[i]) {
				x = i;
				fl = 1;
				break;
			}
		}
		if (x != -1) {
			ans.push_back(x);
			for (int i = 0; i < n; ++i)
				if (s[x][i] == '1')
					++cnt[i];
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < (int)ans.size(); ++i)
		cout << ans[i] + 1 << " ";

	return 0;
}