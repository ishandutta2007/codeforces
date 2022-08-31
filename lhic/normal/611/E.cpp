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

multiset<int> ss;
int arr[300000];
int n;
int a, b, c;

int check(int x) {
	int n = ss.size() - x;
	auto it = ss.begin();
	for (int i = 0; i < n; ++i, ++it) {
		arr[i] = *it;
	}
	int ca = 0;
	int cb = 0;
	int cab = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > a + b) {
			return 0;
		}
		if (arr[i] > b)
			++cab;
		else if (arr[i] > a)
			++cb;
		else
			++ca;
	}
	while (ca > cb)
		--ca, ++cb;
	if (cab + max(ca, cb) <= x)
		return 1;
	else
		return 0;
}

int main() {
	int ans = 0;
	scanf("%d", &n);
	scanf("%d%d%d", &a, &b, &c);
	int xx[3];
	xx[0] = a;
	xx[1] = b;
	xx[2] = c;
	sort(xx, xx + 3);
	a = xx[0];
	b = xx[1];
	c = xx[2];
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	for (int i = 0; i < n; ++i)
		ss.insert(arr[i]);
	for (int i = 0; i < n; ++i) {
		if (arr[i] > a + b + c) {
			cout << -1 << "\n";
			return 0;
		}
	}
	while (!ss.empty()) {
		int x = *ss.rbegin();
		if (x > b + c) {
			++ans;
			ss.erase(ss.find(x));
		}
		else if (x > a + c) {
			++ans;
			ss.erase(ss.find(x));
			auto it = ss.upper_bound(a);
			if (it != ss.begin()) {
				--it;
				ss.erase(it);
			}
		}
		else if (x > a + b && x > c) {
			++ans;
			ss.erase(ss.find(x));
			auto it = ss.upper_bound(b);
			if (it != ss.begin()) {
				--it;
				ss.erase(it);
			}
		}
		else if (x > c) {
			++ans;
			ss.erase(ss.find(x));
			auto it = ss.upper_bound(c);
			if (it != ss.begin()) {
				--it;
				ss.erase(it);
			}
		}
		else {
			break;
		}
	}

	int l = 0;
	int r = (int)ss.size();
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (check(m))
			r = m;
		else
			l = m;
	}

	cout << ans + r << "\n";
	return 0;
}