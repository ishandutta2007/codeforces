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
int cntn, cntm;

int get(int a) {
	if (a == 0)
		return 1;
	int ans = 0;
	while (a)
		++ans, a /= 7;
	return ans;
}

int check(int a, int b) {
	int go[8];
	for (int i = 0; i < 7; ++i)
		go[i] = 0;
	for (int i = 0; i < cntn; ++i) {
		go[a % 7]++;
		a /= 7;
	}
	for (int i = 0; i < cntm; ++i) {
		go[b % 7]++;
		b /= 7;
	}
	for (int i = 0; i < 7; ++i)
		if (go[i] > 1)
			return 0;
	return 1;
}


int main() {
	int n, m;
	cin >> n >> m;
	cntn = get(n - 1);
	cntm = get(m - 1);
	if (cntn + cntm > 7) {
		cout << 0 << "\n";
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (check(i, j))
				++ans;
	cout << ans << "\n";
	return 0;
}