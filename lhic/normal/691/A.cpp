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
	int n;
	cin >> n;
	int a = 0;
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		a += b;
	}
	if (n == 1) {
		if (a == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	else {
		if (a == n - 1) {
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
	return 0;
}