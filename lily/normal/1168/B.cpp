#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mp(a, b) make_pair
#define x first
#define y second
#define read(x) scanf("%d", &x)
#define readl(x) scanf("%lld", &x)
#define readd(x) scanf("%lf", &x)

#define N 300305

char s[N];
int E[N];

int main() {
	scanf("%s", s + 1);
	int n = (int)strlen(s + 1);
	for (int j = 1; j <= n; j++) E[j] = n + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 31; j++) {
			if (i + j * 2 <= n && s[i] == s[i + j] && s[i] == s[i + j * 2]) {
				E[i] = i + j * 2;
				break;
			}
		}
	}
	for (int j = n - 1; j; j--) E[j] = min(E[j], E[j + 1]);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += n + 1 - E[i];
	}
	cout << ans << endl;
}