#include <bits/stdc++.h>
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
#define sz(a) int((a).size())
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 2e5 + 10;
int n, a[N], b[N], cnta[N], cntb[N];

i64 s3(int n) { return 1ll * n * (n - 1) * (n - 2) / 6; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T--; ) {
		cin >> n;
		for(int i = 1; i <= n; i++) cnta[i] = cntb[i] = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
			cnta[a[i]]++, cntb[b[i]]++;
		}
		i64 ans = s3(n);
		for(int i = 1; i <= n; i++) {
			ans -= 1ll * (cnta[a[i]] - 1) * (cntb[b[i]] - 1);
		}
		cout << ans << endl;
	}
	return 0;
}