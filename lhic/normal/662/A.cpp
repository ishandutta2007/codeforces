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

const int MAXN = 600000;

int n;
ll a[MAXN];
ll sum;
int en[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		sum ^= x;
		a[i] = y ^ x;
	}
	int now = 0;
	for (int i = 0; i < 60; ++i) {
		int fl = 0;
		for (int j = now; j < n; ++j) {
			if ((a[j] >> i) & 1) {
				swap(a[now], a[j]);
				fl = 1;
				break;
			}
		}
		if (!fl)
			continue;
		for (int j = 0; j < now; ++j)
			if ((a[j] >> i) & 1)
				a[j] ^= a[now];
		for (int j = now + 1; j < n; ++j)
			if ((a[j] >> i) & 1)
				a[j] ^= a[now];
		if ((sum >> i) & 1)
			en[now] = 1;
		else
			en[now] = 0;
		++now;
	}
	for (int i = 0; i < now; ++i)
		if (en[i])
			sum ^= a[i];
	if (sum == 0) {
		ll q = 1ll << now;
		cout << q - 1 << "/" << q << "\n";
	}
	else {
		cout << "1/1\n";
	}
	return 0;
}