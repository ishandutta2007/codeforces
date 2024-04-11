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


int main() {
	char c;
	int y;
	scanf("%c%d", &c, &y);
	--y;
	int x = c - 'a';
	int cnt = 0;
	for (int i = -1; i <= 1; ++i)
		for (int j = -1; j <= 1; ++j) {
			if (x + i >= 0 && x + i < 8 && y + j >= 0 && y + j < 8)
				++cnt;
		}
	cout << cnt - 1 << "\n";
	return 0;
}