#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 500005;

char tmp[Maxn];
int n, q;
string dict[Maxn];
ii id[Maxn];
char str[Maxn];
int slen;

void Read(string &s)
{
	scanf("%s", tmp);
	s = tmp;
}

bool Less(const int &a, const int &b) { return str[a] < str[b]; }

int rnk[Maxn];
int cur[Maxn];
int cnt[Maxn], nxt[Maxn];
bool dif1[Maxn], dif2[Maxn];
int bef[Maxn], plcp[Maxn];
int lcp[Maxn];

void buildSA()
{
	for (int i = 0; i < slen; i++)
		cur[i] = i;
	sort(cur, cur + slen, Less);
	for (int i = 0; i < slen; i++) {
		dif1[i] = i == 0 || str[cur[i - 1]] != str[cur[i]];
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
		while (bef[i] + l < slen && i + l < slen && str[bef[i] + l] == str[i + l]) l++;
		plcp[i] = l;
		l = max(l - 1, 0);
	}
	for (int i = 0; i < slen; i++)
		lcp[i] = plcp[cur[i]];
}

struct node {
	int L, R, sum;
	node(int L = 0, int R = 0, int sum = 0): L(L), R(R), sum(sum) {}
};
vector <node> nodes;

void createNew()
{
	nodes.push_back(node());
}

int getLst() { return int(nodes.size()) - 1; }

int par[Maxn], siz[Maxn];
int tr[Maxn];
vector <int> jon[Maxn], chk[Maxn];
int ql[Maxn], qr[Maxn], qk[Maxn];
int res[Maxn];
vector <int> my[Maxn];

void Insert(int v, int l, int r, int x)
{
	nodes[v].sum++;
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) {
			if (!nodes[v].L) { createNew(); nodes[v].L = getLst(); }
			Insert(nodes[v].L, l, m, x);
		} else {
			if (!nodes[v].R) { createNew(); nodes[v].R = getLst(); }
			Insert(nodes[v].R, m + 1, r, x);
		}
	}
}

void Union(int &v, int u)
{
	if (u == 0) return;
	if (v == 0) { v = u; return; }
	nodes[v].sum += nodes[u].sum;
	Union(nodes[v].L, nodes[u].L);
	Union(nodes[v].R, nodes[u].R);
}

int Get(int v, int l, int r, int a, int b)
{
	if (v == 0) return 0;
	if (l == a && r == b) return nodes[v].sum;
	else {
		int res = 0;
		int m = l + r >> 1;
		if (a <= m) res += Get(nodes[v].L, l, m, a, min(m, b));
		if (m + 1 <= b) res += Get(nodes[v].R, m + 1, r, max(m + 1, a), b);
		return res;
	}
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b]; par[b] = a;
	Union(tr[a], tr[b]);
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		Read(dict[i]);
		for (int j = 0; j < dict[i].length(); j++) {
			id[slen] = ii(i, j);
			str[slen++] = dict[i][j];
		}
		id[slen] = ii(i, dict[i].length());
		str[slen++] = '#';
	}
	buildSA();
	calcLCP();
	createNew();
	for (int i = 0; i < slen; i++) {
		par[i] = i;
		siz[i] = 1;
		createNew();
		tr[i] = getLst();
		Insert(tr[i], 0, n - 1, id[cur[i]].first);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &ql[i], &qr[i], &qk[i]); ql[i]--; qr[i]--; qk[i]--;
		my[qk[i]].push_back(i);
	}
	for (int i = 1; i < slen; i++)
		jon[lcp[i]].push_back(i);
	for (int i = 0; i < slen; i++)
		if (id[cur[i]].second == 0)
			chk[dict[id[cur[i]].first].length()].push_back(i);
	for (int i = slen; i > 0; i--) {
		for (int j = 0; j < jon[i].size(); j++)
			unionSet(jon[i][j] - 1, jon[i][j]);
		for (int j = 0; j < chk[i].size(); j++) {
			int ind = chk[i][j];
			int k = id[cur[ind]].first;
			int v = getPar(ind);
			for (int z = 0; z < my[k].size(); z++) {
				int qind = my[k][z];
				res[qind] = Get(tr[v], 0, n - 1, ql[qind], qr[qind]);
			}
		}
	}
	for (int i = 0; i < q; i++)
		printf("%d\n", res[i]);
    return 0;
}