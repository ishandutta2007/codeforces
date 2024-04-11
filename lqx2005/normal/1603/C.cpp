#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<int, int>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 1e5 + 10, P = 998244353;
int n, a[N], cnt[N];
void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int sum = 0, ans = 0;
	for(int i = 1; i <= n; i++) {
		cnt[i] = 1;
		(sum += 1ll * (cnt[i] - 1) * i % P) %= P; 
		for(int j = i - 1; j >= 1; j--) {
			if(a[j + 1] / cnt[j + 1] < (a[j] + cnt[j] - 1) / cnt[j]) {
				int now = a[j + 1] / cnt[j + 1];
				(sum += P - 1ll * (cnt[j] - 1) * j % P) %= P;
				cnt[j] = (a[j] + now - 1) / now;
				(sum += 1ll * (cnt[j] - 1) * j % P) %= P;
			} else {
				break;
			}
		}
		(ans += sum) %= P;
	}
	printf("%d\n", ans);
	return;
}

int main() {
	int T;
	for(scanf("%d", &T); T--; ) {
		solve();
	}
	return 0;
}