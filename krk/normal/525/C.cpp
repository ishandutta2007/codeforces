#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000006;

int n;
ll res;
int orig[Maxn];
int prs[Maxn];

void Reduce(int &a, int &b, int sub)
{
	int tk = min(a, sub); a -= tk; sub -= tk;
	b -= sub;
}

int main()
{
	scanf("%d", &n);
	while (n--) {
		int l; scanf("%d", &l);
		orig[l]++;
	}
	int add = 0;
	for (int i = Maxn - 1; i >= 1; i--) {
		prs[i] = (orig[i] + add) / 2;
		Reduce(add, orig[i], 2 * prs[i]);
		add = orig[i];
	}
	bool has = false;
	int prv = Maxn;
	for (int i = Maxn - 1; i >= 1; i--)
		if (prs[i]) {
			if (has) { res += ll(i) * prv; prs[i]--; }
			res += ll(prs[i] / 2) * i * i; prs[i] %= 2;
			has = prs[i]; prv = i;
		}
	printf("%I64d\n", res);
	return 0;
}