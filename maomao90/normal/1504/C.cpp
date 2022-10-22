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
#define MAXN 200005

int t;
int n;
char s[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", &s);
		int diffs[2] = {0, 0};
		string ans[2] = {"", ""};
		bool pos = 1;
		REP (i, 0, n) {
			if (s[i] == '0') {
				diffs[0]--;
				diffs[1]++;
				ans[0] += ")";
				ans[1] += "(";
				swap(diffs[0], diffs[1]);
				swap(ans[0], ans[1]);
			} else {
				if (i != n - 1 && (diffs[1] == 0 || diffs[0] == 1)) {
					diffs[0]++;
					diffs[1]++;
					ans[0] += "(";
					ans[1] += "(";
				} else {
					diffs[0]--;
					diffs[1]--;
					ans[0] += ")";
					ans[1] += ")";
				}
			}
// 			printf("%s %s\n", ans[0].c_str(), ans[1].c_str());
			if (diffs[1] < 0) {
				pos = 0;
				break;
			}
		}
		pos &= diffs[0] == 0 && diffs[1] == 0;
		if (pos) {
			printf("YES\n");
			printf("%s\n", ans[0].c_str());
			printf("%s\n", ans[1].c_str());
		} else {
			printf("NO\n");
		}
	}
	return 0;
}