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

const int MAXN = 210000;

ll ans;

int a[MAXN * 2];
ll sm[MAXN];
int mx[MAXN];
int gg[MAXN];
int n;



void solve(int x) {
	if (x == n)
		return;
	for (int i = 0; i < x; ++i)
		mx[i] = 0;
	for (int i = 0; i < n; ++i)
		mx[i % x] = max(mx[i % x], a[i]);
	for (int i = 0; i <= n; ++i)
		sm[i] = 0;
	int r = 0;
	for (int i = 0; i < n; ++i) {
		r = max(r, i);
		while (r - i < n && mx[r % x] == a[r])
			++r;
		++sm[r - i];
	}
	for (int i = n; i >= 1; --i) {
		sm[i - 1] += sm[i];
		if (gg[i] == x)
			ans += sm[i];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		gg[i] = __gcd(i, n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
		a[i + n] = a[i];
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			if (i * i == n)
				solve(i);
			else
				solve(i), solve(n / i);
		}
	}
	cout << ans << "\n";
	return 0;
}