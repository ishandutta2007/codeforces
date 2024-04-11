#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 1005;
const int Maxm = 100005;

int n, m;
int a[Maxm], b[Maxm];
int nd;
vector <int> S, E;
vector <bool> mE;
int c, p[Maxn], siz[Maxn];
int e;
vector <int> res;

void initSet()
{
	for (int i = 1; i <= n; i++) { p[i] = i; siz[i] = 1; }
	c = n;
}

int getPar(int x) { return p[x] == x? x: p[x] = getPar(p[x]); }

void unionSet(int a, int b)
{
	int para = getPar(a), parb = getPar(b);
	if (siz[para] >= siz[parb]) { siz[para] += siz[parb]; p[parb] = para; }
	else { siz[parb] += siz[para]; p[para] = parb; }
	c--;
}

bool getMust(const vector <int> &S, const vector <int> &E, vector <bool> &mE, int &res)
{
	initSet();
	for (int i = 0; i < S.size(); i++) {
		int ind = S[i];
		if (getPar(a[ind]) != getPar(b[ind])) unionSet(a[ind], b[ind]);
	}
	res = 0;
	for (int i = 0; i < E.size(); i++) {
		int ind = E[i];
		if (getPar(a[ind]) != getPar(b[ind])) { unionSet(a[ind], b[ind]); mE[i] = true; res++; }
	}
	return c == 1 && res <= nd;
}

int main()
{
	scanf("%d %d", &n, &m);
	if (n % 2 == 0) { printf("-1\n"); return 0; }
	nd = (n - 1) / 2;
	for (int i = 1; i <= m; i++) {
		char ch; scanf("%d %d %c", &a[i], &b[i], &ch);
		if (ch == 'S') {
			if (a[i] != b[i]) S.push_back(i);
		} else if (a[i] != b[i]) { E.push_back(i); mE.push_back(false); }
	}
	if (!getMust(S, E, mE, e)) { printf("-1\n"); return 0; }
	initSet();
	for (int i = 0; i < E.size(); i++) {
		int ind = E[i];
		if (mE[i]) { unionSet(a[ind], b[ind]); res.push_back(ind); }
	}
	for (int i = 0; i < E.size(); i++) {
		int ind = E[i];
		if (getPar(a[ind]) != getPar(b[ind]) && e < nd) { unionSet(a[ind], b[ind]); res.push_back(ind); e++; }
	}
	if (e < nd) { printf("-1\n"); return 0; }
	for (int i = 0; i < S.size(); i++) {
		int ind = S[i];
		if (getPar(a[ind]) != getPar(b[ind])) { unionSet(a[ind], b[ind]); res.push_back(ind); }
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}