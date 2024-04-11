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

const int Maxn = 300005;
const int Maxb = 21;

struct node {
	node *ch[2];
	int cnt;
	node() { ch[0] = ch[1] = NULL; cnt = 0; }
};

int n, m;
bool was[Maxn];
node *tr;

void Insert(node *tr, int lvl, int num)
{
	tr->cnt++;
	if (lvl < 0) return;
	int my = bool(num & 1 << lvl);
	if (!tr->ch[my]) tr->ch[my] = new node();
	Insert(tr->ch[my], lvl - 1, num);
}

int Get(node *tr, int lvl, int num)
{
	if (!tr || lvl < 0) return 0;
	int my = bool(num & 1 << lvl);
	if (tr->ch[my] && tr->ch[my]->cnt == (1 << lvl))
		return (1 << lvl) | Get(tr->ch[!my], lvl - 1, num);
	else return Get(tr->ch[my], lvl - 1, num);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		was[a] = true;
	}
	tr = new node();
	for (int i = 0; i < Maxn; i++) if (was[i])
		Insert(tr, Maxb - 1, i);
	int cur = 0;
	while (m--) {
		int x; scanf("%d", &x); cur ^= x;
		printf("%d\n", Get(tr, Maxb - 1, cur));
	}
	return 0;
}