#include <bits/stdc++.h>
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 2e5 + 10;
int n, a[N];
map<i64, int> buc;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T--; ) {
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		i64 sum = 0;
		for(int i = 1; i <= n; i++) sum += a[i];
		int g = __gcd((i64)n, sum);
		sum /= g;
		if(n / g > 2) {
			cout << 0 << endl;
			continue;
		}
		if(n == g) sum *= 2;
		buc.clear();
		i64 ans = 0;
		for(int i = 1; i <= n; i++) {
			if(buc.count(sum - a[i])) {
				ans += buc[sum - a[i]];
			}
			buc[a[i]]++;
		}
		cout << ans << endl;
	}
	return 0;
}