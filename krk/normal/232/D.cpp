#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 2000000000;
const int Maxn = 100005;
const int Maxm = 2 * Maxn;
const int Maxk = 20;

int n;
int h[Maxn];
int str[Maxm], slen;
int cur[Maxm], rank[Maxm];
int cnt[Maxm], nxt[Maxm];
bool dif1[Maxm], dif2[Maxm];
int bef[Maxm], plcp[Maxm];
int lcp[Maxm];
int U[Maxm][Maxk], D[Maxm][Maxk];
int q;
int l[Maxn], r[Maxn], a[Maxn], b[Maxn];
vector <ii> L, R;
int BIT[Maxm];
int res[Maxn];

bool Less(const int &a, const int &b) { return str[a] < str[b]; }

void buildSA()
{
	for (int i = 0; i < slen; i++)
		cur[i] = i;
	sort(cur, cur + slen, Less);
	for (int i = 0; i < slen; i++)
		dif1[i] = i == 0 || str[cur[i - 1]] != str[cur[i]];
	for (int h = 1; h < slen; h <<= 1) {
		int buck = 0;
		for (int i = 0, j; i < slen; i = j) {
			j = i + 1;
			while (j < slen && !dif1[j]) j++;
			nxt[i] = j; buck++;
		}
		if (buck == slen) return;
		for (int i = 0; i < slen; i = nxt[i]) {
			cnt[i] = 0;
			for (int j = i; j < nxt[i]; j++)
				rank[cur[j]] = i;
		}
		cnt[rank[slen - h]]++; dif2[rank[slen - h]] = true;
		for (int i = 0; i < slen; i = nxt[i]) {
			for (int j = i; j < nxt[i]; j++) {
				int bef = cur[j] - h;
				if (bef >= 0) {
					int head = rank[bef];
					rank[bef] = head + cnt[head]++;
					dif2[rank[bef]] = true;
				}
			}
			for (int j = i; j < nxt[i]; j++) {
				int bef = cur[j] - h;
				if (bef >= 0 && dif2[rank[bef]])
					for (int k = rank[bef] + 1; dif2[k] && !dif1[k]; k++)
						dif2[k] = false;
			}
		}
		for (int i = 0; i < slen; i++) {
			cur[rank[i]] = i;
			dif1[i] |= dif2[i];
		}
	}
}

void calcLCP()
{
	bef[cur[0]] = -1;
	for (int i = 1; i < slen; i++) bef[cur[i]] = cur[i - 1];
	int l = 0;
	for (int i = 0; i < slen; i++) if (bef[i] != -1) {
		while (bef[i] + l < slen && i + l < slen && str[bef[i] + l] == str[i + l]) l++;
		plcp[i] = l;
		l = max(0, l - 1);
	}
	for (int i = 0; i < slen; i++) lcp[i] = plcp[cur[i]];
}

void Insert(int x)
{
	for (int i = x; i <= slen; i += i & -i)
		BIT[i]++;
}

int Get(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &h[i]);
	for (int i = 0; i + 1 < n; i++) {
		str[i] = h[i] - h[i + 1]; str[n + i] = -str[i];
	}
	str[n - 1] = Inf; slen = 2 * n - 1;
	buildSA();
	for (int i = 0; i < slen; i++) rank[cur[i]] = i;
	calcLCP();
	for (int i = 0; i < slen; i++)
		U[i][0] = lcp[i];
	for (int j = 1; j < Maxk; j++)
		for (int i = 0; i < slen; i++)
			if (i < 1 << j - 1) U[i][j] = 0;
			else U[i][j] = min(U[i][j - 1], U[i - (1 << j - 1)][j - 1]);
	for (int i = 0; i < slen; i++)
		D[i][0] = lcp[i + 1];
	for (int j = 1; j < Maxk; j++)
		for (int i = 0; i < slen; i++)
			if (i + (1 << j - 1) >= slen) D[i][j] = 0;
			else D[i][j] = min(D[i][j - 1], D[i + (1 << j - 1)][j - 1]);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &l[i], &r[i]);
		if (l[i] == r[i]) continue;
		int ind = rank[l[i] - 1];
		a[i] = ind;
		for (int k = Maxk - 1; k >= 0; k--)
			if (U[a[i]][k] >= r[i] - l[i]) a[i] -= 1 << k;
		b[i] = ind;
		for (int k = Maxk - 1; k >= 0; k--)
			if (D[b[i]][k] >= r[i] - l[i]) b[i] += 1 << k;
		L.push_back(ii(n + l[i] - (r[i] - l[i]) - 2, i)); R.push_back(ii(n + r[i], i));
	}
	sort(L.begin(), L.end());
	int lst = n - 1;
	for (int i = 0; i < L.size(); i++) {
		if (L[i].first < lst) continue;
		while (lst < L[i].first) Insert(rank[++lst] + 1);
		int ind = L[i].second;
		res[ind] += Get(b[ind] + 1) - Get(a[ind]);
	}
	fill(BIT, BIT + slen + 1, 0);
	sort(R.begin(), R.end());
	lst = slen;
	for (int i = R.size() - 1; i >= 0; i--) {
		if (R[i].first > lst) continue;
		while (R[i].first < lst) Insert(rank[--lst] + 1);
		int ind = R[i].second;
		res[ind] += Get(b[ind] + 1) - Get(a[ind]);
	}
	for (int i = 0; i < q; i++)
		printf("%d\n", l[i] == r[i]? n - 1: res[i]);
	return 0;
}