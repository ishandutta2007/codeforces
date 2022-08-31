#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

vector<int> vv[201000];
int lst[201000];
int n;
int a[201000];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		int x = upper_bound(lst, lst + n, a[i], cmp) - lst;
		vv[x].push_back(a[i]);
		lst[x] = a[i];
		mx = max(mx, x);
	}
	for (int i = 0; i <= mx; ++i) {
		for (int j: vv[i])
			printf("%d ", j);
		printf("\n");
	}
	return 0;
}