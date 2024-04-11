#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
#define fir first
#define sec second

const int maxn = 2e5 + 10;
int n;
char s[maxn];
void work() {
	scanf("%d%s", &n, s + 1);
	ll ans = 0, len = 0, x = 0, y = 0;
	for (int i = 1; i <= n; ++i) {
		++len;
		if (i == n || s[i] != s[i + 1])
			ans = max(ans, len * len), len = 0;
		if (s[i] == '0') ++x;
		else ++y;
	}
	ans = max(ans, x * y);
	printf("%lld\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}