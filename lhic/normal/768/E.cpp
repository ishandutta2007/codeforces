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

int n;
int cc[100];
int fl[100];
map<ll, int> mm;

void run(int i, ll now, int x) {
	if (x >= i) {
		run(i + 1, now ^ (1ll << (i - 1)), x - i);
		run(i + 1, now, x);
	}
	else {
		for (int j = 0; j <= x; ++j)
			fl[j] = 0;
		for (int j = 1; j <= x; ++j) {
			if (!((now >> (j - 1)) & 1))
				fl[mm[now ^ (1ll << (j - 1))]] = 1;
		}
		for (int j = 0; j <= x; ++j)
			if (!fl[j]) {
				mm[now] = j;
				return;
			}
	}
}

int calc(int x) {
	mm.clear();
	run(1, 0, x);
	return mm[0];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		cc[x] ^= 1;
	}
	int now = 0;
	for (int i = 1; i <= 60; ++i) {
		int g = calc(i);
		if (cc[i])
			now ^= g;
	}
	if (now == 0) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	return 0;
}