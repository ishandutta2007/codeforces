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
ll n, sum[maxn], stk[maxn], tp, ss[maxn];
char s[maxn];
struct BIT {
	ll c[maxn << 1];
	void add(ll x, ll y) { for (; x < (maxn << 1); x += x & -x) c[x] += y; }
	ll ask(ll x) {
		ll res = 0;
		for (; x > 0; x &= x - 1) res += c[x];
		return res;
	}
} tr, tr2;
void work() {
	scanf("%lld%s", &n, s + 1);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
	stk[tp = 0] = n + 1;
	for (int i = n; i >= 1; --i) {
		while (tp && sum[i] <= sum[stk[tp]]) --tp;
		stk[++tp] = i, ss[tp] = ss[tp - 1] + sum[i] * (stk[tp - 1] - i);
		int l = 1, r = tp, mid, pos = -1;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (sum[stk[mid]] <= sum[i - 1]) pos = mid, l = mid + 1;
			else r = mid - 1;
		}
		if (pos != -1) ans += sum[i - 1] * (n + 1 - stk[pos]) - ss[pos];
	}
	for (int i = 1; i <= n; ++i)
		tr.add(sum[i - 1] + n + 1, 1),
		tr2.add(sum[i - 1] + n + 1, -sum[i - 1]),
		ans += sum[i] * tr.ask(sum[i] + n + 1) + tr2.ask(sum[i] + n + 1);
	for (int i = 1; i <= n; ++i)
		tr.add(sum[i - 1] + n + 1, -1),
		tr2.add(sum[i - 1] + n + 1, sum[i - 1]);
	printf("%lld\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}