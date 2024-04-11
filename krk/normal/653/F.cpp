#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int Maxm = 1000015;
const int Maxs = 2097152;

int n;
char str[Maxn];
int sa[Maxn], rnk[Maxn];
int nxt[Maxn], cnt[Maxn];
bool dif1[Maxn], dif2[Maxn];
int bef[Maxn], plcp[Maxn], lcp[Maxn];
int my[Maxn];
vector <int> pos[Maxm];
int mn[Maxs];
ll res;

bool Less(const int &a, const int &b) { return str[a] < str[b]; }

void buildSA()
{
	for (int i = 0; i < n; i++)
		sa[i] = i;
	sort(sa, sa + n, Less);
	for (int i = 0; i < n; i++)
		dif1[i] = i == 0 || str[sa[i]] != str[sa[i - 1]];
	for (int h = 1; h < n; h <<= 1) {
		int bucks = 0;
		for (int i = 0, j; i < n; i = j) {
			j = i + 1;
			while (j < n && !dif1[j]) j++;
			nxt[i] = j;
			bucks++;
		}
		if (bucks == n) return;
		for (int i = 0; i < n; i = nxt[i]) {
			cnt[i] = 0;
			for (int j = i; j < nxt[i]; j++)
				rnk[sa[j]] = i;
		}
		cnt[rnk[n - h]]++; dif2[rnk[n - h]] = true;
		for (int i = 0; i < n; i = nxt[i]) {
			for (int j = i; j < nxt[i]; j++) {
				int v = sa[j] - h;
				if (v >= 0) {
					int head = rnk[v];
					rnk[v] = head + cnt[head]++;
					dif2[rnk[v]] = true;
				}
			}
			for (int j = i; j < nxt[i]; j++) {
				int v = sa[j] - h;
				if (v >= 0 && dif2[rnk[v]])
					for (int k = rnk[v] + 1; !dif1[k] && dif2[k]; k++)
						dif2[k] = false;
			}
		}
		for (int i = 0; i < n; i++) {
			sa[rnk[i]] = i;
			dif1[i] |= dif2[i];
		}
	}
}

void calcLCP()
{
	bef[sa[0]] = -1;
	for (int i = 1; i < n; i++)
		bef[sa[i]] = sa[i - 1];
	int l = 0;
	for (int i = 0; i < n; i++) if (bef[i] != -1) {
		while (bef[i] + l < n && i + l < n && str[bef[i] + l] == str[i + l]) l++;
		plcp[i] = l;
		l = max(l - 1, 0);
	}
	for (int i = 0; i < n; i++)
		lcp[i] = plcp[sa[i]];
}

void Create(int v, int l, int r)
{
	if (l == r) mn[v] = my[l];
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		mn[v] = min(mn[2 * v], mn[2 * v + 1]);
	}
}

int Get(int v, int l, int r, int a, int b, int lim)
{
	if (mn[v] >= lim) return n;
	if (l == r) return l;
	int m = l + r >> 1;
	if (b <= m) return Get(2 * v, l, m, a, b, lim);
	if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b, lim);
	int got = Get(2 * v, l, m, a, m, lim);
	if (got == n) got = Get(2 * v + 1, m + 1, r, m + 1, b, lim);
	return got;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	buildSA();
	calcLCP();
	int st = 0;
	for (int i = 0; i < n; i++) {
		my[i] = st; pos[st + Maxn].push_back(i);
		st += str[i] == '('? 1: -1;
	}
	my[n] = st; pos[st + Maxn].push_back(n);
	Create(1, 0, n);
	for (int i = 0; i < n; i++) {
		int p = Get(1, 0, n, sa[i], n, my[sa[i]]);
		if (sa[i] + lcp[i] < p) {
			int ind = my[sa[i]] + Maxn;
			res += upper_bound(pos[ind].begin(), pos[ind].end(), p) - 
				   upper_bound(pos[ind].begin(), pos[ind].end(), sa[i] + lcp[i]);
		}
	}
	printf("%I64d\n", res);
	return 0;
}