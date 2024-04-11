#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 1e+9 + 7;

int main() {
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n, i, j, a, b = 0;
	string s;
	int m[16], r[16];
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> m[i];
	for (i = 0; i < n; ++i)
		cin >> r[i];
	for (i = 1; i <= 720720; ++i) {
		bool succ = false;
		for (j = 0; j < n; ++j)
			if ((i % m[j]) == r[j])
				succ = true;
		if (succ)
			++b;
	}
	cout << ld(b) / 720720;

	return 0;
}