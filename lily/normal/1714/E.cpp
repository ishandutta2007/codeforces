#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)


bool check(int x, int y) {
	while (x < y && x % 10 != 2 && x % 10 != 0) {
		x += x % 10;
	}
	if (x > y) return false;
	if (x == y) return true;
	if (x < y && x % 10 == 0) return false;
	int z = 2 + 4 + 8 + 6;
	x += (y - x) / z * z;
	while (x < y && x % 10 != 0) {
		x += x % 10;
	}
	return x == y;
}

int go(int x) {
	while (x % 10 != 2 && x % 10 != 0) {
		x += x % 10;
	}
	if (x % 10 == 0) return x;
	return x + (2 + 4 + 8 + 6) * 100;
}

bool work() {
	int n;
	read(n);
	vector <int> a;
	for (int i = 1; i <= n; i++) {
		int x;
		read(x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	a.back() = go(a.back());
	for (auto i : a) if (!check(i, a.back())) return false;
	return true;
}

int main() {
	int T;
	read(T);
	while (T--) puts (work() ? "Yes" : "No");

}