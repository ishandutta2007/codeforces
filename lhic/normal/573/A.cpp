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
	scanf("%d", &n);
	int lst = -1;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		while (a % 2 == 0)
			a /= 2;
		while (a % 3 == 0)
			a /= 3;
		if (lst == -1)
			lst = a;
		if (a != lst) {
			cout << "No\n";
			return 0;
		}

	}
	cout << "Yes\n";
	return 0;
}