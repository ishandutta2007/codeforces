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
int cnt[3000];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++cnt[a];
	}
	for (int i = 0; i < 1000; ++i) {
		if (cnt[i] && cnt[i + 1] && cnt[i + 2]) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}