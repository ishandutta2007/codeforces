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

string s[60000];

bool cmp(const string& a, const string& b) {
	return (a + b) < (b + a);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	sort(s, s + n, cmp);
	for (int i = 0; i < n; ++i)
		cout << s[i];
	cout << "\n";
	return 0;
}