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
#include <ctime>


typedef long long ll;
typedef long double ld;

using namespace std;

ll P;
const ll M1 = 1000000007;
const ll M2 = 1000000009;
int n;
int a[2510][2510];
int b[2510 * 2510];
int vvc = 0;
int vv[3500000];
ll pw1[2510];
ll pw2[2510];


bool cmp(int x, int y) {
	return b[x] > b[y];
}

struct hs {
	ll a, b;
	bool operator==(const hs& x) {
		return a == x.a && b == x.b;
	}
};


hs hsh[2510];

void add(int x, int y, int a) {
	hsh[x].a += pw1[y] * a;
	hsh[x].a %= M1;
	hsh[x].b += pw2[y] * a;
	hsh[x].b %= M2;
}

int main() {
	srand(time(NULL));
	P = rand() % (1000000000 - 100000000) + 10000000;
	scanf("%d", &n);
	pw1[0] = 1;
	pw2[0] = 1;
	for (int i = 0; i < n; ++i) {
		pw1[i + 1] = (pw1[i] * P) % M1;
		pw2[i + 1] = (pw2[i] * P) % M2;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]), b[i * n + j] = a[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (a[i][j] != a[j][i]) {
				cout << "NOT MAGIC\n";
				return 0;
			}
			if (a[i][i] != 0) {
				cout << "NOT MAGIC\n";
				return 0;
			}
		}
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			vv[vvc++] = i * n + j;

	sort(vv, vv + vvc, cmp);
	
	int cnt = 1;
	int lst = 0;
	for (int i = 0; i < vvc; ++i) {
		int x = vv[i] / n;
		int y = vv[i] % n;
		if (!(hsh[x] == hsh[y])) {
			cout << "NOT MAGIC\n";
			return 0;
		}
		if (i == vvc - 1 || b[vv[i]] != b[vv[i + 1]]) {
			for (int j = lst; j <= i; ++j) {
				int x = vv[j] / n;
				int y = vv[j] % n;
				add(x, y, cnt);
				add(y, x, cnt);
			}
			++cnt;
			lst = i + 1;
		}
	}

	cout << "MAGIC\n";

	return 0;
}