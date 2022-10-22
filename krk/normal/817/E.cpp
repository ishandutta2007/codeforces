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

const int Maxb = 28;

struct node {
	node *ch[2];
	int cnt;
	node() { ch[0] = ch[1] = NULL; cnt = 0; }
};

int q;
node *tr;

int Cnt(node *tr) { return tr? tr->cnt: 0; }

void Add(node *tr, int lvl, int x, int add)
{
	tr->cnt += add;
	if (lvl < 0) return;
	int ind = bool(x & 1 << lvl);
	if (!tr->ch[ind]) tr->ch[ind] = new node();
	Add(tr->ch[ind], lvl - 1, x, add);
}

int Get(node *tr, int lvl, int p, int l)
{
	if (!tr) return 0;
	if (lvl < 0) return 0;
	int zer = bool(p & 1 << lvl);
	int one = !zer;
	if (l & 1 << lvl) return Cnt(tr->ch[zer]) + Get(tr->ch[one], lvl - 1, p, l);
	else return Get(tr->ch[zer], lvl - 1, p, l);
}

int main()
{
	tr = new node();
	scanf("%d", &q);
	while (q--) {
		int typ, p, l; scanf("%d %d", &typ, &p);
		if (typ == 1) Add(tr, Maxb - 1, p, 1);
		else if (typ == 2) Add(tr, Maxb - 1, p, -1);
		else {
			scanf("%d", &l);
			printf("%d\n", Get(tr, Maxb - 1, p, l));
		}
	}
	return 0;
}