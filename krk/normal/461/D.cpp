#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxk = 100005;
const int mod = 1000000007;

int n, k;
int a[Maxk], b[Maxk], c[Maxk];
int N, comp, par[Maxn], siz[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] >= siz[b]) { siz[a] += siz[b]; par[b] = a; }
	else { siz[b] += siz[a]; par[a] = b; }
	comp--;
}

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int getRes(int st)
{
	N = 2 * ((n + 1 - st) / 2 + 1);
	for (int i = 0; i < N; i++) {
		par[i] = i; siz[i] = 1;
	}
	comp = N;
	for (int i = 0; i < k; i++) {
		int d = a[i] + b[i];
		if (d % 2 == st) {
			int lft = abs(a[i] - b[i]);
			while (lft % 2 != st) lft++;
			int rig = min(a[i] + b[i], 2 * (n - 1) - a[i] - b[i]);
			while (rig % 2 != st) rig--;
			int rl = (lft - st) / 2, rr = (rig - st) / 2;
			unionSet(2 * rl, 2 * (rr + 1) + c[i]);
			unionSet(2 * rl + 1, 2 * (rr + 1) + 1 - c[i]);
		}
	}
	for (int i = 0; 2 * i + 1 < N; i++)
		if (getPar(2 * i) == getPar(2 * i + 1))
			return 0;
	return toPower(2, (comp - 2) / 2);
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		char ch; scanf("%d %d %c", &a[i], &b[i], &ch);
		a[i]--; b[i]--; c[i] = ch == 'o';
	}
	printf("%d\n", int(ll(getRes(0)) * getRes(1) % mod));
	return 0;
}