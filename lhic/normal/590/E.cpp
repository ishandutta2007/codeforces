#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef double ld;

using namespace std;

const int MAXLEN = 10001000;

char str[MAXLEN];

struct node {
	int go[2];
	int tr, nr, p, suf, sym;
	node() {
		tr = nr = p = -1;
		suf = 0;
		go[0] = go[1] = sym = 0;
	}
};

node mem[MAXLEN];

int nowmem = 1;

int newn() {
	return nowmem++;
}


void add(char *s, int x) {
	int n = strlen(s);
	int now = 0;
	for (int i = 0; i < n; ++i) {
		if (mem[now].go[s[i] - 'a'])
			now = mem[now].go[s[i] - 'a'];
		else {
			int y = newn();
			mem[y].p = now;
			mem[y].sym = s[i] - 'a';
			now = mem[now].go[s[i] - 'a'] = y;
		}
	}
	mem[now].tr = x;
}


void calc(int x) {
	if (!x)
		return;
	if (mem[x].p == 0)
		mem[x].suf = 0;
	else
		mem[x].suf = mem[mem[mem[x].p].suf].go[mem[x].sym];
	if (mem[mem[x].suf].tr != -1)
		mem[x].nr = mem[mem[x].suf].tr;
	else
		mem[x].nr = mem[mem[x].suf].nr;
	for (int i = 0; i < 2; ++i) {
		if (!mem[x].go[i])
			mem[x].go[i] = mem[mem[x].suf].go[i];
	}
}

void build_ak() {
	queue<int> qu;
	qu.push(0);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int i = 0; i < 2; ++i)
			if (mem[x].go[i])
				qu.push(mem[x].go[i]);
		calc(x);
	}
}

const int MAXN = 1000;

int was[MAXN * 2];
int p[MAXN * 2];
vector<int> eds[MAXN];
char *s[MAXN];
int ed[MAXN][MAXN];

int dfs(int v) {
	was[v] = 1;
	for (int u: eds[v])
		if (p[u] == -1)
			return (p[u] = v, p[v] = u, 1);
	for (int u: eds[v])
		if (!was[p[u]])
			if (dfs(p[u]))
				return (p[u] = v, p[v] = u, 1);
	return 0;
}

void dfs2(int v) {
	was[v] = 1;
	for (int u: eds[v])
		if (u != p[v])
			if (!was[u]) {
				was[u] = 1;
				if (p[u] != -1 && !was[p[u]])
					dfs2(p[u]);
			}
}

int main() {
	int n;
	scanf("%d", &n);
	char *s2 = str;
	for (int i = 0; i < n; ++i) {
		scanf(" %s", s2);
		s[i] = s2;
		s2 += strlen(s2) + 1;
	}
	for (int i = 0; i < n; ++i)
		add(s[i], i);
	build_ak();
	for (int i = 0; i < n; ++i) {
		int now = 0;
		int l = strlen(s[i]);
		for (int j = 0; j < l; ++j) {
			now = mem[now].go[s[i][j] - 'a'];
			if (mem[now].nr != -1)
				ed[i][mem[now].nr] = 1;
			if (mem[now].tr != -1 && j != l - 1)
				ed[i][mem[now].tr] = 1;
		}
	}

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (ed[i][k] && ed[k][j])
					ed[i][j] = 1;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (ed[i][j])
				eds[i].push_back(j + n);

	for (int i = 0; i < 2 * n; ++i)
		p[i] = -1;

	int ch = 1;
	while (ch) {
		ch = 0;
		memset(was, 0, sizeof(was[0]) * n);
		for (int i = 0; i < n; ++i)
			if (p[i] == -1)
				ch |= dfs(i);
	}
	memset(was, 0, sizeof(was[0]) * 2 * n);
	for (int i = 0; i < n; ++i)
		if (p[i] == -1)
			dfs2(i);
	vector<int> ans;
	for (int i = 0; i < n; ++i)
		if (was[i] && !was[i + n])
			ans.push_back(i);
	cout << ans.size() << "\n";
	for (int x: ans)
		cout << x + 1 << " ";
	cout << "\n";
	return 0;
}