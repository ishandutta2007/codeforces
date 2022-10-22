#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int mod = 1000000007;

int n, m;
int par[Maxn];
int res = 1;
vector <int> seq;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m + 1; i++)
		par[i] = i;
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		int a, b;
		if (k == 1) {
			scanf("%d", &a); b = m + 1;
		} else scanf("%d %d", &a, &b);
		a = getPar(a);
		b = getPar(b);
		if (a != b) {
			if (a > b) swap(a, b);
			par[a] = b;
			res = 2 * res % mod;
			seq.push_back(i + 1);
		}
	}
	printf("%d %d\n", res, int(seq.size()));
	for (int i = 0; i < seq.size(); i++)
		printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    return 0;
}