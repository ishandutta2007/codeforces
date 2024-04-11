#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define MOD 998244353

LL power(LL x, LL y) {
	LL ret = 1;
	for ( ; y; y >>= 1) {
		if (y & 1) (ret *= x) %= MOD;
		(x *= x) %= MOD;
	}
	return ret;
}


int main() {
	int n, m;
	cin >> n >> m;
	cout << power(2, n + m) << endl;


}