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
ld pp[1200][1200];
ld sm[1200];
ld l[1200];
ld dd[1200];
int en[1200];

void upd(int x) {
	for (int i = 0; i < n; ++i)
		if (!en[i]) {
			sm[i] += l[i] * pp[i][x] * (1 + dd[x]);
			l[i] *= (1 - pp[i][x]);
			if (l[i] < 1e-10)
				l[i] = 0;
		}
}

ld get(int x) {
	if (1 - l[x] > 1e-10)
		return (sm[x] + l[x]) / (1 - l[x]);
	else
		return 1e16;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int p;
			scanf("%d", &p);
			pp[i][j] = p / 100.0;
		}
	for (int i = 0; i < n; ++i)
		l[i] = 1;
	en[n - 1] = 1;
	dd[n - 1] = 0;
	upd(n - 1);
	while (!en[0]) {
		int mn = -1;
		ld xx = 0;
		for (int i = 0; i < n; ++i)
			if (!en[i] && (mn == -1 || get(i) < xx))
				mn = i, xx = get(i);
		en[mn] = 1;
		dd[mn] = get(mn);
		upd(mn);
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << dd[0] << "\n";
	return 0;
}