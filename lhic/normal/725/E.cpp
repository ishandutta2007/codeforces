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
const int MAXN = 201000;

int n;
int c;
int a[MAXN];
int go[MAXN];
ll sm[MAXN];
int bb[MAXN];

int fnd(int x, int y) {
	if (a[x] > y)
		return y;
	int l = -1;
	int r = x + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (sm[x + 1] - sm[mid] > y)
			l = mid;
		else
			r = mid;
	}
	return y - (sm[x + 1] - sm[r]);
}

int main() {
	scanf("%d", &c);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	sm[0] = 0;
	a[n] = c;
	for (int i = 1; i <= n + 1; ++i)
		sm[i] = sm[i - 1] + a[i - 1];
	go[n - 1] = c;
	for (int i = n - 1; i > 0; --i) {
		if (go[i] >= a[i])
			go[i - 1] = go[i] - a[i];
		else
			go[i - 1] = go[i];
	}
	bb[0] = 1;
	bb[c] = 1;
	for (int i = 1; i < c; ++i) {
		int x = upper_bound(a, a + n + 1, i) - a;
		--x;
		if (sm[x + 1] < i) {
			bb[i] = 0;
		}
		else {
			x = fnd(x, i);
			bb[i] = bb[x];
		}
	}
	for (int i = 0; i < n; ++i) {
		int l = a[i] + 1;
		int r = min(go[i] - 1, a[i + 1]);
		if (l > r)
			continue;
		l = go[i] - l;
		r = go[i] - r;
		swap(l, r);
		for (int j = r; j >= l; --j) {
			int x = fnd(i, j);
			if (!bb[x]) {
				cout << go[i] - j << "\n";
				return 0;
			}
		}
	}
	cout << "Greed is good\n";
	return 0;
}