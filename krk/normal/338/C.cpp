#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 8;
const int Inf = 1000000000;

int n;
ll a[Maxn], cap[Maxn];
int pcnt[Maxn];
int cur, res = Inf;
int add;

void Gen(int v, int comp)
{
	if (v == n) res = min(res, cur + (comp > 1));
	else {
		Gen(v + 1, comp + 1);
		for (int i = v + 1; i < n; i++) if (cap[i] % a[v] == 0ll) {
			cur -= pcnt[v]; cap[i] /= a[v];
			Gen(v + 1, comp);
			cur += pcnt[v]; cap[i] *= a[v];
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	sort(a, a + n);
	cur = n;
	for (int i = 0; i < n; i++) {
		cap[i] = a[i];
		ll num = a[i];
		for (ll j = 2; j * j <= num; j++)
			while (num % j == 0) {
				num /= j; pcnt[i]++;
			}
		if (num > 1) pcnt[i]++;
		if (pcnt[i] > 1) cur += pcnt[i];
	}
	Gen(0, 0);
	printf("%d\n", res);
	return 0;
}