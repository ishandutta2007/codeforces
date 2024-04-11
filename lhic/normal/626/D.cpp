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


int n;
int a[4000];
ll dd[6000];
ll go[12000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			++dd[a[j] - a[i]];
	for (int i = 0; i <= a[n - 1]; ++i)
		for (int j = 0; j <= a[n - 1]; ++j)
			go[i + j] += dd[i] * dd[j];
	for (int j = 0; j <= 2 * a[n - 1] + 10; ++j)
		go[j + 1] += go[j];
	ld cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			cnt += go[a[j] - a[i] - 1];
	ld gg = n * (n - 1) / 2;
	cnt /= gg;
	cnt /= gg;
	cnt /= gg;
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << cnt << "\n";
	return 0;
}