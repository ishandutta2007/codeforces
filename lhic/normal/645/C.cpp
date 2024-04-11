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

const int MAXN = 120000;

int pr[MAXN];
char s[MAXN];
int n, k;


void init() {
	pr[0] = 0;
	for (int i = 0; i < n; ++i)
		pr[i + 1] = pr[i] + (s[i] == '0' ? 1 : 0);
}

int get(int l, int r) {
	return pr[r] - pr[l];
}

int main() {
	scanf("%d%d", &n, &k);
	scanf(" %s", s);
	init();
	int l = 0;
	int r = n;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		int fl = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1')
				continue;
			if (get(max(0, i - m), i) + get(i + 1, min(n, i + m + 1)) >= k) {
				fl = 1;
				break;
			}
		}
		if (fl)
			r = m;
		else
			l = m;
	}
	cout << r << "\n";
	return 0;
}