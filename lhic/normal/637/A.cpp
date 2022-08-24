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

int cnt[1200000];

int main() {
	int n;
	cin >> n;
	int mx = 0;
	int mxb = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++cnt[a];
		if (cnt[a] > mx) {
			mx = cnt[a];
			mxb = a;
		}
	}
	cout << mxb << "\n";
	return 0;
}