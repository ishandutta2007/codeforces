#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 2005;
const int Maxm = 4000005;

int n;
int d[Maxn][Maxn];
ii E[Maxm];
int elen;
ii srt[Maxm];
int slen;
int par[Maxn], has[Maxn][Maxn], hlen[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool Join(int para, int parb, int a, int b, int edg)
{
	for (int i = 0; i < hlen[para]; i++) {
		int u = has[para][i];
		for (int j = 0; j < hlen[parb]; j++) {
			int v = has[parb][j];
			if (ll(d[u][a]) + ll(edg) + ll(d[b][v]) != ll(d[u][v]))
				return false;
		}
	}
	par[parb] = para;
	for (int i = 0; i < hlen[parb]; i++)
		has[para][hlen[para]++] = has[parb][i];
	return true;
}

bool Connect(int a, int b, int len)
{
	int para = getPar(a), parb = getPar(b);
	if (para == parb) return true;
	if (hlen[para] >= hlen[parb]) return Join(para, parb, a, b, len);
	else return Join(parb, para, b, a, len);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &d[i][j]);
			if (i == j && d[i][j] != 0) { printf("NO\n"); return 0; }
			if (i != j && d[i][j] == 0) { printf("NO\n"); return 0; }
			if (i > j && d[i][j] != d[j][i]) { printf("NO\n"); return 0; }
			if (i < j) {
				E[elen] = ii(i, j);
				srt[slen++] = ii(d[i][j], elen); elen++;
			}
		}
	for (int i = 0; i < n; i++) {
		par[i] = i; has[i][0] = i; hlen[i] = 1;
	}
	sort(srt, srt + slen);
	for (int i = 0; i < slen; i++) {
		int e = srt[i].second;
		if (!Connect(E[e].first, E[e].second, d[E[e].first][E[e].second])) { printf("NO\n"); return 0; }
	}
	printf("YES\n");
	return 0;
}