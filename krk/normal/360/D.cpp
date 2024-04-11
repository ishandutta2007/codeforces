#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 10005;
const int Maxm = 1000005;

int n, m, p;
int a[Maxn];
int b;
int dv[Maxm], dlen;
int freq[Maxn];
int ans[Maxn];
int res;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int toPow(int a, int b)
{
	int res = 1;
	while (b) {
		if (b & 1) res = ll(res) * a % p;
		b >>= 1; a = ll(a) * a % p;
	}
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		int tmp; scanf("%d", &tmp);
		b = gcd(b, tmp);
	}
	for (int i = 1; i * i <= p - 1; i++)
		if ((p - 1) % i == 0) {
			dv[dlen++] = i;
			if ((p - 1) / i != i)
				dv[dlen++] = (p - 1) / i;
		}
	sort(dv, dv + dlen);
	for (int i = 0; i < n; i++) {
		a[i] = toPow(a[i], b);
		for (int j = 0; j < dlen; j++)
			if (toPow(a[i], dv[j]) == 1) { 
				freq[i] = (p - 1) / dv[j]; 
				break; 
			}
	}
	sort(freq, freq + n);
	for (int i = n - 1; i >= 0; i--) {
		ans[i] = (p - 1) / freq[i];
		for (int j = i + 1; j < n; j++)
			if (freq[j] % freq[i] == 0)
				ans[i] -= ans[j];
		res += ans[i];
	}
	printf("%d\n", res);
	return 0;
}