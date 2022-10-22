#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 5005;
const int Maxm = 100005;
const int Maxw = 100005;

int n, m, k;
int a[Maxm], b[Maxm];
vector <ii> S, C;
vector <bool> mC;
int c, p[Maxn], siz[Maxn];
vector <int> res;

void initSet()
{
	for (int i = 1; i <= n; i++) p[i] = i, siz[i] = 1;
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

int Take(int dif)
{
	int res = 0;
	initSet();
	int i = 0, j = 0;
	while (i < C.size() || j < S.size())
		if (i < C.size() && (j == S.size() || C[i].first + dif <= S[j].first)) {
			int ind = C[i].second; i++;
			if (getPar(a[ind]) != getPar(b[ind])) { res++; unionSet(a[ind], b[ind]); }
		} else {
			int ind = S[j].second; j++;
			if (getPar(a[ind]) != getPar(b[ind])) unionSet(a[ind], b[ind]);
		}
	return c > 1? -Maxw - 1: res;
}

void Collect(int dif)
{
	initSet();
	int i = 0, j = 0;
	while (i < C.size() || j < S.size())
		if (i < C.size() && (j == S.size() || C[i].first + dif <= S[j].first)) {
			int ind = C[i].second; i++;
			if (getPar(a[ind]) != getPar(b[ind]) && k) { k--; unionSet(a[ind], b[ind]); res.push_back(ind); }
		} else {
			int ind = S[j].second; j++;
			if (getPar(a[ind]) != getPar(b[ind])) { unionSet(a[ind], b[ind]); res.push_back(ind); }
		}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int c; scanf("%d %d %d", &a[i], &b[i], &c);
		if (a[i] == 1 || b[i] == 1) { C.push_back(ii(c, i)); mC.push_back(false); }
		else S.push_back(ii(c, i));
	}
	sort(C.begin(), C.end()); sort(S.begin(), S.end());
	int l = -Maxw, r = Maxw;
	int dif = -Maxw - 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (Take(mid) >= k) { dif = mid; l = mid + 1; }
		else r = mid - 1;
	}
	if (dif < -Maxw) { printf("-1\n"); return 0; }
	Collect(dif);
	if (res.size() < n - 1) { printf("-1\n"); return 0; }
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}