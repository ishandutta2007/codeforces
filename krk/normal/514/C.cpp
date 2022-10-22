#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxl = 600005;
const int param = 157143269;
const int mod1 = 1000000007;
const int mod2 = 1000000009;

int pw1[Maxl], pw2[Maxl];
set <ii> T;
int n, m;
char str[Maxl];
int cur1[Maxl], cur2[Maxl];
int slen;

int main()
{
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < Maxl; i++) {
		pw1[i] = ll(pw1[i - 1]) * param % mod1;
		pw2[i] = ll(pw2[i - 1]) * param % mod2;
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str); slen = strlen(str);
		int res1 = 0, res2 = 0;
		for (int i = 0; i < slen; i++) {
			res1 = (ll(res1) * param + str[i] - 'a' + 1) % mod1;
			res2 = (ll(res2) * param + str[i] - 'a' + 1) % mod2;
		}
		T.insert(ii(res1, res2));
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", str); slen = strlen(str);
		cur1[slen] = cur2[slen] = 0;
		for (int i = slen - 1; i >= 0; i--) {
			cur1[i] = (ll(pw1[slen - 1 - i]) * (str[i] - 'a' + 1) + cur1[i + 1]) % mod1;
			cur2[i] = (ll(pw2[slen - 1 - i]) * (str[i] - 'a' + 1) + cur2[i + 1]) % mod2;
		}
		int res1 = 0, res2 = 0;
		bool ok = false;
		for (int i = 0; i < slen && !ok; i++) {
			char old = str[i];
			for (char ch = 'a'; ch <= 'c' && !ok; ch++) if (ch != old) {
				int tmp1 = ((ll(res1) * param + ch - 'a' + 1) % mod1 * pw1[slen - 1 - i] + cur1[i + 1]) % mod1;
				int tmp2 = ((ll(res2) * param + ch - 'a' + 1) % mod2 * pw2[slen - 1 - i] + cur2[i + 1]) % mod2;
				ok = T.find(ii(tmp1, tmp2)) != T.end();
			}
			str[i] = old;
			res1 = (ll(res1) * param + str[i] - 'a' + 1) % mod1;
			res2 = (ll(res2) * param + str[i] - 'a' + 1) % mod2;
		}
		printf("%s\n", ok? "YES": "NO");
	}
	return 0;
}