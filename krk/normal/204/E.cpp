#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;
const int Maxm = 21;

char tmp[Maxn];
int n, k;
string a[Maxn];
ii id[Maxn];
int rmq[Maxn][Maxm];
char s[Maxn];
int slen;
int rnk[Maxn];
int cur[Maxn];
int cnt[Maxn], nxt[Maxn];
bool dif1[Maxn], dif2[Maxn];
int bef[Maxn], plcp[Maxn];
int lcp[Maxn];
map <int, int> M;
int L[Maxn], R[Maxn];
ll res[Maxn];

void Read(string &s)
{
	scanf("%s", tmp);
	s = tmp;
}

bool Less(const int &a, const int &b) { return s[a] < s[b]; }

void buildSA()
{
	for (int i = 0; i < slen; i++)
		cur[i] = i;
	sort(cur, cur + slen, Less);
	for (int i = 0; i < slen; i++) {
		dif1[i] = i == 0 || s[cur[i - 1]] != s[cur[i]];
		dif2[i] = false;
	}
	for (int h = 1; h < slen; h <<= 1) {
		int buck = 0;
		for (int i = 0, j; i < slen; i = j) {
			j = i + 1;
			while (j < slen && !dif1[j]) j++;
			nxt[i] = j;
			buck++;
		}
		if (buck == slen) break;
		for (int i = 0; i < slen; i = nxt[i]) {
			cnt[i] = 0;
			for (int j = i; j < nxt[i]; j++)
				rnk[cur[j]] = i;
		}
		cnt[rnk[slen - h]]++; dif2[rnk[slen - h]] = true;
		for (int i = 0; i < slen; i = nxt[i]) {
			for (int j = i; j < nxt[i]; j++) {
				int s = cur[j] - h;
				if (s >= 0) {
					int head = rnk[s];
					rnk[s] = head + cnt[head]++;
					dif2[rnk[s]] = true;
				}
			}
			for (int j = i; j < nxt[i]; j++) {
				int s = cur[j] - h;
				if (s >= 0 && dif2[rnk[s]])
					for (int k = rnk[s] + 1; !dif1[k] && dif2[k]; k++) dif2[k] = false;
			}
		}
		for (int i = 0; i < slen; i++) {
			cur[rnk[i]] = i;
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
		while (bef[i] + l < slen && i + l < slen && s[bef[i] + l] == s[i + l]) l++;
		plcp[i] = l;
		l = max(l - 1, 0);
	}
	for (int i = 0; i < slen; i++)
		lcp[i] = plcp[cur[i]];
}

int Get(int l, int r)
{
	int res = Maxn;
	for (int j = Maxm - 1; j >= 0; j--)
		if (l + (1 << j) <= r + 1) {
			res = min(res, rmq[l][j]);
			l += 1 << j;
		}
	return res;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		Read(a[i]);
		for (int j = 0; j < a[i].length(); j++) {
			id[slen] = ii(i, j);
			s[slen++] = a[i][j];
		}
		id[slen] = ii(i, -1);
		s[slen++] = '#';
	}
	buildSA();
	calcLCP();
	for (int i = 0; i < slen; i++) {
		if (id[cur[i]].second != -1)
			lcp[i] = min(lcp[i], int(a[id[cur[i]].first].length()) - id[cur[i]].second);
		rmq[i][0] = lcp[i];
	}
	for (int j = 1; j < Maxm; j++)
		for (int i = 0; i + (1 << j) <= slen; i++)
			rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << j - 1)][j - 1]);
	int pnt = n - 1;
	for (int i = n; i < slen; i++) {
		pnt = max(pnt, i);
		while (pnt < slen && M.size() < k) {
			M[id[cur[pnt]].first]++;
			pnt++;
		}
		if (M.size() < k) break;
		int cand = min(int(a[id[cur[i]].first].length()) - id[cur[i]].second, Get(i + 1, pnt - 1));
		L[i] = max(L[i], cand);
		R[pnt - 1] = max(R[pnt - 1], cand);
		if (--M[id[cur[i]].first] == 0)
			M.erase(id[cur[i]].first);
	}
	for (int i = 1; i < slen; i++)
		L[i] = max(L[i], min(L[i - 1], lcp[i]));
	for (int i = slen - 2; i >= 0; i--)
		R[i] = max(R[i], min(R[i + 1], lcp[i + 1]));
	for (int i = 0; i < slen; i++)
		if (id[cur[i]].second != -1)
			res[id[cur[i]].first] += max(L[i], R[i]);
	for (int i = 0; i < n; i++)
		printf("%I64d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}