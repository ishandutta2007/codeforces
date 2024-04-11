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
const int MAXN = 210000;

int n, a, b, k;
char s[MAXN];

int main() {
	scanf("%d%d%d%d", &n, &a, &b, &k);
	scanf(" %s", s);
	s[n] = '1';
	int lst = -1;
	int cur = 0;
	for (int i = 0; i <= n; ++i) {
		if (s[i] == '1') {
			int cnt = (i - lst - 1);
			cur += cnt / b;
			lst = i;
		}
	}
	int nd = cur - a + 1;
	int cnt = 0;
	vector<int> vv;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			++cnt;
			if (cnt == b) {
				cnt = 0;
				vv.push_back(i + 1);
			}
		}
		else {
			cnt = 0;
		}
	}
	printf("%d\n", nd);
	for (int i = 0; i < nd; ++i)
		printf("%d ", vv[i]);
	printf("\n");
	return 0;
}