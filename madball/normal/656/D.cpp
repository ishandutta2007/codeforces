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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n, i = 0, j;
	string s;
	cin >> n;
	for (; n; n /= 8)
		if ((n % 8) == 1)
			++i;
	cout << i;
	return 0;
}