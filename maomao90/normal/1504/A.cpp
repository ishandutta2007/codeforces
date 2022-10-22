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
char s[MAXN];
int n;
string ans;

bool check() {
	string rev = ans;
	reverse(ALL(rev));
	return ans != rev;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf(" %s", &s);
		n = strlen(s);
		bool pos = 0;
		REP (i, 0, n) {
			if (s[i] != 'a') pos = 1;
		}
		if (!pos) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		ans = s;
		ans = 'a' + ans;
		if (check()) {
			printf("%s\n", ans.c_str());
			continue;
		}
		ans = s;
		ans += 'a';
		assert(check());
		printf("%s\n", ans.c_str());
	}
	return 0;
}