#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int t;

char s[Maxn];
int slen;
int rank[Maxn];
int cur[Maxn];
int cnt[Maxn], nxt[Maxn];

bool dif1[Maxn], dif2[Maxn];
int bef[Maxn], plcp[Maxn];
int lcp[Maxn];

int par[Maxn], siz[Maxn], got[Maxn];
vector <int> has[Maxn];
ll res;

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
				rank[cur[j]] = i;
		}
		cnt[rank[slen - h]]++; dif2[rank[slen - h]] = true;
		for (int i = 0; i < slen; i = nxt[i]) {
			for (int j = i; j < nxt[i]; j++) {
				int s = cur[j] - h;
				if (s >= 0) {
					int head = rank[s];
					rank[s] = head + cnt[head]++;
					dif2[rank[s]] = true;
				}
			}
			for (int j = i; j < nxt[i]; j++) {
				int s = cur[j] - h;
				if (s >= 0 && dif2[rank[s]])
					for (int k = rank[s] + 1; !dif1[k] && dif2[k]; k++) dif2[k] = false;
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
		while (bef[i] + l < slen && i + l < slen && s[bef[i] + l] == s[i + l]) l++;
		plcp[i] = l;
		l = max(l - 1, 0);
	} else plcp[i] = 0;
	for (int i = 0; i < slen; i++)
		lcp[i] = plcp[cur[i]];
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void Merge(int a, int b, int on)
{
	res += ll(siz[a]) * ll(siz[a]) * (got[a] - on);
	res += ll(siz[b]) * ll(siz[b]) * (got[b] - on);
	got[a] = on;
	siz[a] += siz[b]; par[b] = a;
}

void unionSet(int a, int b, int on)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] >= siz[b]) Merge(a, b, on);
	else Merge(b, a, on);
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s); slen = strlen(s);
		buildSA(); calcLCP();
		res = 0;
		for (int i = 0; i <= slen; i++)
			has[i].clear();
		for (int i = 0; i < slen; i++) {
			par[i] = i, siz[i] = 1, got[i] = slen - cur[i];
			has[lcp[i]].push_back(i);
		}
		for (int i = slen; i > 0; i--)
			for (int j = 0; j < has[i].size(); j++)
				unionSet(has[i][j] - 1, has[i][j], i);
		for (int j = 0; j < has[0].size(); j++) {
			int p = getPar(has[0][j]);
			res += ll(siz[p]) * siz[p] * got[p];
		}
		printf("%I64d\n", res);
	}
	return 0;
}