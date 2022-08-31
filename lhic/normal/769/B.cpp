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

int n;
int en[1200];
int a[1200];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	en[0] = 1;
	vector<pair<int, int> > vv;
	int ch = 1;
	while (ch) {
		ch = 0;
		for (int i = 0; i < n; ++i)
			if (en[i] && a[i]) {
				int mx = -1;
				for (int j = 0; j < n; ++j) {
					if (!en[j] && (mx == -1 || a[j] > a[mx]))
						mx = j;
				}
				if (mx != -1) {
					ch = 1;
					vv.push_back(make_pair(i, mx));
					--a[i];
					en[mx] = 1;
				}
			}
	}
	for (int i = 0; i < n; ++i) {
		if (!en[i]) {
			cout << -1 << "\n";
			return 0;
		}
	}
	cout << vv.size() << "\n";
	for (int i = 0; i < vv.size(); ++i)
		cout << vv[i].first + 1 << " " << vv[i].second + 1 << "\n";
	return 0;
}