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

const int Maxn = 200005;

int slen;
char s[Maxn];
char vals[Maxn];
int rank[Maxn];
int cur[Maxn];
int cnt[Maxn], nxt[Maxn];
bool dif1[Maxn], dif2[Maxn];
int bef[Maxn], plcp[Maxn];
int lcp[Maxn];

int siz[Maxn], par[Maxn], my[Maxn];
vector <int> jon[Maxn];
int mx;
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
	}
	for (int i = 0; i < slen; i++)
		lcp[i] = plcp[cur[i]];
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] >= siz[b]) { siz[a] += siz[b]; my[a] += my[b]; mx = max(mx, my[a]); par[b] = a; }
	else { siz[b] += siz[a]; my[b] += my[a]; mx = max(mx, my[b]); par[a] = b; }
}

int main()
{
	scanf("%d", &slen);
	scanf("%s", s);
	scanf("%s", vals);
	reverse(s, s + slen); reverse(vals, vals + slen);
	for (int i = 0; i < slen; i++)
		if (vals[i] == '0') res = max(res, ll(slen - i));
	buildSA();
	calcLCP();
	for (int i = 1; i < slen; i++)
		jon[lcp[i]].push_back(i);
	for (int i = 0; i < slen; i++) {
		par[i] = i, siz[i] = 1;
		my[i] = vals[cur[i]] == '0';
	}
	for (int i = slen + 1; i >= 1; i--) {
		for (int j = 0; j < jon[i].size(); j++)
			unionSet(jon[i][j] - 1, jon[i][j]);
		res = max(res, ll(mx) * i);
	}
	cout << res << endl;
	return 0;
}