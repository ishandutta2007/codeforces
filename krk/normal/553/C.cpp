#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

const int Maxn = 100005;

int n, m;
int comp, P[Maxn], totop[Maxn], S[Maxn];
int res;

void solvePar(int x)
{
	if (x == P[x]) return;
	solvePar(P[x]);
	totop[x] ^= totop[P[x]]; P[x] = P[P[x]];
}

int getPar(int x) { solvePar(x); return P[x]; }

int getTop(int x) { solvePar(x); return totop[x]; }

bool unionSet(int a, int b, int nd)
{
	int para = getPar(a), parb = getPar(b);
	if (para == parb)
		return (getTop(a) ^ getTop(b)) == nd;
	else {
		if (S[para] >= S[parb]) {
			S[para] += S[parb]; totop[parb] = getTop(a) ^ getTop(b) ^ nd; P[parb] = para; 
		} else {
			S[parb] += S[para]; totop[para] = getTop(a) ^ getTop(b) ^ nd; P[para] = parb;
		}
		comp--;
		return true;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		P[i] = i, S[i] = 1;
	comp = n;
	while (m--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		if (!unionSet(a, b, 1 - c)) { printf("0\n"); return 0; }
	}
	res = 1;
	for (int i = 0; i < comp - 1; i++)
		res = ll(res) * 2 % mod;
	printf("%d\n", res);
	return 0;
}