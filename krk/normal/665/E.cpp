#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxb = 31;

struct trie {
	trie *ch[2];
	int cnt;
	trie() { ch[0] = ch[1] = NULL; cnt = 0; }
};

int n, k;
trie *tr;
ll res;

int Cnt(trie *tr) { return tr? tr->cnt: 0; }

int Get(trie *tr, int lvl, int num, int k)
{
	if (tr == NULL) return 0;
	if (lvl < 0) return 0;
	if (bool(k & 1 << lvl)) return Get(tr->ch[bool(num & 1 << lvl) ^ 1], lvl - 1, num, (k ^ 1 << lvl));
	else return Cnt(tr->ch[bool(num & 1 << lvl) ^ 1]) + Get(tr->ch[bool(num & 1 << lvl)], lvl - 1, num, k);
}

void Insert(trie *tr, int lvl, int num)
{
	tr->cnt++;
	if (lvl < 0) return;
	int ind = bool(num & 1 << lvl);
	if (!tr->ch[ind]) tr->ch[ind] = new trie();
	Insert(tr->ch[ind], lvl - 1, num);
}

int main()
{
	scanf("%d %d", &n, &k); k--;
	tr = new trie();
	Insert(tr, Maxb - 1, 0);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		cur ^= a;
		res += Get(tr, Maxb - 1, cur, k);
		Insert(tr, Maxb - 1, cur);
	}
	printf("%I64d\n", res);
	return 0;
}