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
	ll n, i, j = 0;
	string s;
	char c;
	cin >> s;
	for (i = 0; i < s.size(); ++i) {
		c = s[i];
		j += (c >= 'a' ? c - 'a' + 1 : c - 'A' + 1) * ((int)(c > '@' && c < ']') - (int)(c > '`' && c < '{'));
	}
	cout << j;
	return 0;
}