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
ll a[120000];
ll b[120000];
const ll MOD = 10007;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i), b[i] = a[i];
	sort(a, a + n);
	sort(b, b + n);
	reverse(b, b + n);
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans = (ans + a[i] * b[i]) % MOD;
	cout << ans << "\n";
	return 0;
}