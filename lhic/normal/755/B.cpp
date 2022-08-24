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

int n, m;
char buf[510];
string s;
vector<string> vv;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf(" %s", buf);
		s = buf;
		vv.push_back(s);
	}
	for (int i = 0; i < m; ++i) {
		scanf(" %s", buf);
		s = buf;
		vv.push_back(s);
	}
	sort(vv.begin(), vv.end());
	int c = 0;
	for (int i = 0; i < (int)vv.size() - 1; ++i)
		if (vv[i] == vv[i + 1])
			++c;
	int a = n - c;
	int b = m - c;
	if (a > b) {
		cout << "YES\n";
	}
	else if (b > a) {
		cout << "NO\n";
	}
	else {
		if (c % 2 == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}