#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 100005

int t;
int n, k;
char s[MAXN];
char ans[MAXN];

int cnt[30];
bool isPos(int x) {
	memset(cnt, 0, sizeof cnt);
	REP (i, 0, x + 1) {
		cnt[s[i] - 'a']++;
		ans[i] = s[i];
	}
	int ptr = n - 1;
	REP (i, 'a', 'z' + 1) {
		while (cnt[i - 'a'] % k != 0) {
			if (ptr < 0) return 0;
			cnt[i - 'a']++;
			ans[ptr--] = i;
		}
	}
	if (ptr + 1 <= x) {
		return 0;
	}
	RREP (i, ptr, x + 1) {
		ans[i] = 'z';
	}
	REP (i, 0, n) {
		if (ans[i] > s[i]) return 1;
		if (ans[i] < s[i]) return 0;
	}
	return 1;
}

bool canAns(int x) {
	memset(cnt, 0, sizeof cnt);
	REP (i, 0, x) {
		cnt[ans[i] - 'a']++;
	}
	int ptr = n - 1;
	RREP (i, 'z', 'a') {
		while (cnt[i - 'a'] % k != 0) {
			if (ptr < x) return 0;
			cnt[i - 'a']++;
			ans[ptr--] = i;
		}
	}
	if (ptr + 1 < x) {
		return 0;
	}
	RREP (i, ptr, x) {
		ans[i] = 'a';
	}
	return 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		scanf(" %s", &s);
		if (n % k != 0) {
			printf("-1\n");
			continue;
		}
		int lo = 0, hi = n - 1, mid;
		int res = -1;
		while (lo <= hi) {
			mid = hi + lo >> 1;
			if (isPos(mid)) {
				res = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		int cnt = 0;
		REP (i, 0, res + 1) {
			ans[i] = s[i];
		}
		if (res == n - 1) {
			ans[n] = 0;
			printf("%s\n", ans);
			continue;
		}
		REP (i, s[res + 1] + 1, 'z' + 1) {
			ans[res + 1] = i;
			if (canAns(res + 2)) {
				ans[n] = 0;
				printf("%s\n", ans);
				break;
			}
		}
	}
	return 0;
}