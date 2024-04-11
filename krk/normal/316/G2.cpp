#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxl = 20050;
const int Maxn = 10;
const int Maxm = 21;

int flen;
int n;
char tmp[Maxl];
int tlen;
int L[Maxn], R[Maxn];

int col[Maxl];
char str[Maxl];
int slen;

int cur[Maxl], rank[Maxl];
int nxt[Maxl], has[Maxl];
int buck;
bool dif1[Maxl], dif2[Maxl];

int prv[Maxl];
int aplcp[Maxl], alcp[Maxl];
int mplcp[Maxl], mlcp[Maxl];

int mn[Maxl][Maxm], cnt[Maxl][Maxm][Maxn];

int res;

void readAdd(int wh)
{
	if (wh) { col[slen] = -1; str[slen++] = '#'; }
	scanf("%s", tmp); tlen = strlen(tmp);
	for (int i = 0; i < tlen; i++) {
		col[slen] = wh; str[slen++] = tmp[i];
	}
}

bool Less(const int &a, const int &b)
{
	return str[a] < str[b];
}

void buildSA()
{
	for (int i = 0; i < slen; i++)
		cur[i] = i;
	sort(cur, cur + slen, Less);
	for (int i = 0; i < slen; i++)
		dif1[i] = i == 0 || str[cur[i - 1]] != str[cur[i]];
	for (int h = 1; ; h <<= 1) {
		buck = 0;
		for (int i = 0, j; i < slen; i = j) {
			buck++;
			has[i] = 0;
			j = i;
			do { rank[cur[j]] = i; j++; }
			while (j < slen && !dif1[j]);
			nxt[i] = j;
		}
		if (buck == slen) break;
		for (int i = slen - h; i < slen; i++) {
			rank[i] += has[rank[i]]++; dif2[rank[i]] = true;
		}
		for (int i = 0; i < slen; i = nxt[i]) {
			for (int j = i; j < nxt[i]; j++)
				if (cur[j] >= h) {
					int u = cur[j] - h;
					rank[u] += has[rank[u]]++; dif2[rank[u]] = true;
				}
			for (int j = i; j < nxt[i]; j++)
				if (cur[j] >= h) {
					int u = cur[j] - h;
					for (int k = rank[u] + 1; dif2[k] && !dif1[k]; k++)
						dif2[k] = false;
				}
		}
		for (int i = 0; i < slen; i++) {
			dif1[i] |= dif2[i];
			cur[rank[i]] = i;
		}
	}
}

void calcALCP()
{
	prv[cur[0]] = -1;
	for (int i = 0; i + 1 < slen; i++)
		prv[cur[i + 1]] = cur[i];
	int l = 0;
	for (int i = 0; i < slen; i++)
		if (prv[i] == -1) aplcp[i] = 0;
		else {
			l = max(l - 1, 0);
			while (i + l < slen && prv[i] + l < slen && str[i + l] == str[prv[i] + l])
				l++;
			aplcp[i] = l;
		}
	for (int i = 0; i < slen; i++)
		alcp[i] = aplcp[cur[i]];
}

void calcMLCP()
{
	int myprv = -1;
	for (int i = 0; i < slen; i++)
		if (col[cur[i]] == 0) {
			prv[cur[i]] = myprv; myprv = cur[i];
		}
	int l = 0;
	for (int i = 0; i < slen; i++) if (col[i] == 0)
		if (prv[i] == -1) mplcp[i] = 0;
		else {
			l = max(l - 1, 0);
			while (i + l < slen && prv[i] + l < slen && str[i + l] == str[prv[i] + l])
				l++;
			mplcp[i] = l;
		}
	for (int i = 0; i < slen; i++)
		mlcp[i] = mplcp[cur[i]];
}

void Precompute()
{
	for (int i = 0; i < slen; i++) {
		mn[i][0] = alcp[i];
		if (col[cur[i]] > 0) cnt[i][0][col[cur[i]] - 1] = 1;
	}
	for (int j = 1; j < Maxm; j++)
		for (int i = 0; i + (1 << j) <= slen; i++) {
			int hf = 1 << j - 1;
			mn[i][j] = min(mn[i][j - 1], mn[i + hf][j - 1]);
			for (int k = 0; k < n; k++)
				cnt[i][j][k] = cnt[i][j - 1][k] + cnt[i + hf][j - 1][k];
		}
}

void getRes(int l, int len, int res[])
{
	fill(res, res + n, 0);
	int r = l; l++;
	for (int j = Maxm - 1; j >= 0; j--)
		if (l + (1 << j) <= slen && mn[l][j] >= len) {
			for (int k = 0; k < n; k++)
				res[k] += cnt[l][j][k];
			l += 1 << j;
		}
	for (int j = Maxm - 1; j >= 0; j--)
		if (r - (1 << j) >= 0 && mn[r - (1 << j) + 1][j] >= len) {
			for (int k = 0; k < n; k++)
				res[k] += cnt[r - (1 << j)][j][k];
			r -= 1 << j;
		}
}

bool checkLeft(int l, int len)
{
	int res[Maxn]; getRes(l, len, res);
	for (int i = 0; i < n; i++)
		if (res[i] > R[i]) return false;
	return true;
}

bool checkRight(int l, int len)
{
	int res[Maxn]; getRes(l, len, res);
	for (int i = 0; i < n; i++)
		if (res[i] < L[i]) return false;
	return true;
}

int main()
{
	readAdd(0); flen = tlen;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		readAdd(i + 1); scanf("%d %d", &L[i], &R[i]);
	}
	buildSA();
	calcALCP(); calcMLCP();
	Precompute();
	for (int i = 0; i < slen; i++) if (col[cur[i]] == 0) {
		int l = mlcp[i] + 1, r = flen - cur[i];
		int res1 = r + 1;
		while (l <= r) {
			int m = l + r >> 1;
			if (checkLeft(i, m)) { res1 = m; r = m - 1; }
			else l = m + 1;
		}
		l = mlcp[i] + 1, r = flen - cur[i];
		int res2 = l - 1;
		while (l <= r) {
			int m = l + r >> 1;
			if (checkRight(i, m)) { res2 = m; l = m + 1; }
			else r = m - 1;
		}
		if (res1 <= res2) res += res2 - res1 + 1;
	}
	printf("%d\n", res);
	return 0;
}