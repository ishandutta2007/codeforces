#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
map<int, int, greater<int> > dic;
ll C[25][25];
int main() {
	C[0][0] = 1;
	for (int i = 1; i <= 20; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	int tcase;
	ll k;
	scanf("%d", &tcase);
	while (tcase--) {
		scanf("%lld", &k);
		int max_div;
		dic.clear();
		for (int i = 2; k; i++) {
			dic[k % i]++;
			k /= i;
			max_div = i;
		}
		int n = 0;
		ll ans = 1;
		bool is_zero = false;
		int tmp = max_div;
		for (auto it = dic.begin(); it != dic.end(); it++) {
			int x = it -> first, y = it -> second;
			while (max_div > x && max_div > 1) max_div--, n++;
			ans *= C[n][y];
			if (!x) is_zero = true;
			n -= y;
		}
		if (is_zero) {
			dic[0]--;
			max_div = tmp - 1;
			n = 0;
			ll v = 1;
			for (auto it = dic.begin(); it != dic.end(); it++) {
				int x = it -> first, y = it -> second;
				while (max_div > x && max_div > 1) max_div--, n++;
				v *= C[n][y];
				n -= y;
			}
			ans -= v;
		}

		printf("%lld\n", ans - 1);
	}
	return 0;
}