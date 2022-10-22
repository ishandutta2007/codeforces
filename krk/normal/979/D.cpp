#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxb = 18;
const int Inf = 1000000000;

struct node {
	int mn;
	node *ch[2];
	node() { mn = Inf; ch[0] = ch[1] = NULL; }
};

vector <int> divs[Maxn];
node *trie[Maxn];
bool was[Maxn];
int q;

void Add(node *tr, int num, int lvl)
{
	tr->mn = min(tr->mn, num);
	if (lvl < 0) return;
	int ind = bool(num & 1 << lvl);
	if (!tr->ch[ind]) tr->ch[ind] = new node();
	Add(tr->ch[ind], num, lvl - 1);
}

int getBest(node *tr, int X, int S, int lvl)
{
	if (lvl < 0) return tr->mn;
	int ind = !bool(X & 1 << lvl);
	if (tr->ch[ind])
		if (tr->ch[ind]->mn <= S) return getBest(tr->ch[ind], X, S, lvl - 1);
	ind = !ind;
	if (tr->ch[ind])
		if (tr->ch[ind]->mn <= S) return getBest(tr->ch[ind], X, S, lvl - 1);
	return -1;
}

int main()
{
	for (int i = 1; i < Maxn; i++) {
		for (int j = i; j < Maxn; j += i)
			divs[j].push_back(i);
		trie[i] = new node();
	}
	scanf("%d", &q);
	while (q--) {
		int typ, a, b, c; scanf("%d %d", &typ, &a);
		if (typ == 1) {
			if (!was[a]) {
				for (int i = 0; i < divs[a].size(); i++)
					Add(trie[divs[a][i]], a, Maxb - 1);
				was[a] = true;
			}
		} else {
			scanf("%d %d", &b, &c);
			int X = a, K = b, S = c - a;
			if (X % K != 0) { printf("-1\n"); continue; }
			printf("%d\n", getBest(trie[K], X, S, Maxb - 1));
		}
	}
	return 0;
}