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

char s[100000];

int main() {
	scanf("%s", s);
	int m;
	scanf("%d", &m);
	while (m--) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		--l;
		k %= (r - l);
		k = (r - l) - k;
		k %= (r - l);
		rotate(s + l, s + l + k, s + r);
	}
	printf("%s\n", s);
	return 0;
}