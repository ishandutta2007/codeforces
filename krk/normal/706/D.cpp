#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 30;

struct node {
	int cnt;
	node *ch[2];
	node() { cnt = 0; ch[0] = ch[1] = NULL; }
};

node *t;
int q;

void Insert(node *t, int val, int lvl, int add)
{
	t->cnt += add;
	if (lvl < 0) return;
	int ind = bool(val & 1 << lvl);
	if (!t->ch[ind]) t->ch[ind] = new node();
	Insert(t->ch[ind], val, lvl - 1, add);
}

int getBest(node *t, int val, int lvl)
{
	if (lvl < 0) return 0;
	int ind = bool(val & 1 << lvl);
	if (t->ch[1 - ind])
		if (t->ch[1 - ind]->cnt > 0) return (1 << lvl) | getBest(t->ch[1 - ind], val, lvl - 1);
	if (t->ch[ind])
		if (t->ch[ind]->cnt > 0) return getBest(t->ch[ind], val, lvl - 1);
	return 0;
}

int main()
{
	t = new node();
	Insert(t, 0, Maxn - 1, 1);
	scanf("%d", &q);
	while (q--) {
		char ch; int x; scanf(" %c %d", &ch, &x);
		if (ch == '+') Insert(t, x, Maxn - 1, 1);
		else if (ch == '-') Insert(t, x, Maxn - 1, -1);
		else printf("%d\n", getBest(t, x, Maxn - 1));
	}
	return 0;
}