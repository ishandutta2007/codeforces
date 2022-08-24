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


int main() {
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i <= c; ++i) {
		if (a * i <= c && (c - a * i) % b == 0) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}