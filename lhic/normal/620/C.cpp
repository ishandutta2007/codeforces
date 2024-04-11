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
typedef double ld;

using namespace std;

int n;
map<int, int> mm;
int a[400000];
int nx[400000];
int was[400000];
int l[400000];
int r[400000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	int fl = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (mm.count(a[i]))
			nx[i] = mm[a[i]], fl = 1;
		else
			nx[i] = n;
		mm[a[i]] = i;
	}
	if (!fl) {
		cout << -1 << "\n";
		return 0;
	}
	for (int i = 0; i < n; ++i)
		was[i] = -1;
	int cc = -1;
	int lst = n;
	for (int i = n - 1; i >= 0; --i) {
		was[i] = cc;
		if (nx[i] < lst) {
			++cc;
			for (int j = i; j < lst; ++j)
				was[j] = cc;
			lst = i;
		}
	}
	cout << cc + 1 << "\n";
	++cc;
	for (int i = 0; i < cc; ++i)
		l[i] = n, r[i] = 0;
	for (int i = 0; i < n; ++i)
		r[was[i]] = i;
	for (int i = n - 1; i >= 0; --i)
		l[was[i]] = i;
	for (int i = 0; i < cc; ++i)
		printf("%d %d\n", l[i] + 1, r[i] + 1);
	return 0;
}