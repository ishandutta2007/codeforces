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

int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get(string s) {
	if (s[0] == 'm')
		return 0;
	else if (s == "tuesday")
		return 1;
	else if (s == "wednesday")
		return 2;
	else if (s == "thursday")
		return 3;
	else if (s == "friday")
		return 4;
	else if (s == "saturday")
		return 5;
	else
		return 6;
}

int main() {
	string s, t;
	cin >> s >> t;
	int x = get(s);
	int y = get(t);
	for (int i = 0; i < 11; ++i)
		if (y == (x + d[i]) % 7) {
			cout << "YES\n";
			return 0;
		}
	cout << "NO\n";
	return 0;
}