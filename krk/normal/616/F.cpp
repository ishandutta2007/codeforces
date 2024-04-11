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

const int Maxn = 700005;

char tmp[Maxn];
int n;
string t[Maxn];
int C[Maxn], lft[Maxn];

char s[Maxn];
int slen;
int rank[Maxn];
int cur[Maxn];
int cnt[Maxn], nxt[Maxn];
bool dif1[Maxn], dif2[Maxn];

int bef[Maxn], plcp[Maxn];
int lcp[Maxn];

vector <int> ap[Maxn], jon[Maxn];
int siz[Maxn], par[Maxn];
ll cost[Maxn];
map <ll, int> M;
ll mx;

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
		lcp[i] = min(plcp[cur[i]], lft[cur[i]]);
}

void Insert(ll val) { M[val]++; }

void Remove(ll val)
{
	map <ll, int>::iterator it = M.find(val);
	if (--it->second == 0) M.erase(it);
}

ll Get() { return M.empty()? 0: M.rbegin()->first; }

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	Remove(cost[a]); Remove(cost[b]); Insert(cost[a] + cost[b]);
	if (siz[a] >= siz[b]) { siz[a] += siz[b]; par[b] = a; cost[a] += cost[b]; }
	else { siz[b] += siz[a]; par[a] = b; cost[b] += cost[a]; }
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp); t[i] = tmp;
		for (int j = 0; j < t[i].length(); j++)
			s[slen++] = t[i][j];
		s[slen++] = '#';
	}
	int pnt = 0;
	for (int i = 0; i < n; i++) {
		int c; scanf("%d", &c);
		for (int j = 0; j < t[i].length(); j++) {
			C[pnt] = c; lft[pnt] = t[i].length() - j; pnt++;
		}
		pnt++;
	}
	buildSA(); calcLCP();
	for (int i = 0; i < slen; i++) {
		ap[lft[cur[i]]].push_back(i);
		jon[lcp[i]].push_back(i);
	}
	for (int i = slen; i > 0; i--) {
		for (int j = 0; j < ap[i].size(); j++) {
			int v = ap[i][j];
			siz[v] = 1; par[v] = v; cost[v] = C[cur[v]]; Insert(cost[v]);
		}
		for (int j = 0; j < jon[i].size(); j++) {
			int v = jon[i][j];
			unionSet(v - 1, v);
		}
		mx = max(mx, Get() * ll(i));
	}
	cout << mx << endl;
	return 0;
}