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
#define MAXN 300005

int t;
int n;
char s[3][MAXN];
int lst[3], cnt[3];
vi zeroes, ones;
string ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		zeroes.clear(); ones.clear();
		REP (i, 0, 3) {
			scanf(" %s", &s[i]);
			cnt[i] = 0;
			REP (j, 0, 2 * n) {
				if (s[i][j] == '0') cnt[i]++;
			}
			if (cnt[i] >= n) {
				zeroes.pb(i);
			} else {
				ones.pb(i);
			}
		}
		char c = '0';
		if (zeroes.size() < ones.size()) {
			swap(zeroes, ones);
			c = '1';
		}
		ans = "";
		memset(lst, 0, sizeof lst);
		REP (i, 0, n) {
			REP (k, 0, 2) {
				REP (j, lst[k], 2 * n) {
					if (s[zeroes[k]][j] == c) {
						lst[k] = j + 1;
						break;
					}
					ans += s[zeroes[k]][j];
				}
			}
			ans += c;
		}
		REP (k, 0, 2) {
			REP (j, lst[k], 2 * n) {
				ans += s[zeroes[k]][j];
			}
		}
		while (ans.size() < 3 * n) ans += '0';
		printf("%s\n", ans.c_str());
	}
	return 0;
}