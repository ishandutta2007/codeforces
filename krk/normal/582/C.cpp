#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int g[Maxn];
int n, a[Maxn];
int mx[Maxn];
ll res;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
		g[i] = gcd(i, n);
	for (int i = 1; i < n; i++) if (n % i == 0) {
		for (int j = 0; j < i; j++) {
			mx[j] = 0;
			for (int l = j; l < n; l += i)
				mx[j] = max(mx[j], a[l]);
		}
		int cur = 0, tot = 0;
		for (int j = 0; j < n; j++)
			if (mx[j % i] == a[j]) { cur++; tot += g[cur] == i; }
			else break;
		if (cur == n) res += ll(n) * tot;
		else {
			for (int j = n - 1; j >= 0; j--)
				if (mx[j % i] == a[j]) { cur++; tot += g[cur] == i; res += tot; }
				else { cur = 0; tot = 0; }
		}
	}
	printf("%I64d\n", res);
	return 0;
}