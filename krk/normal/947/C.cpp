#include <bits/stdc++.h>
using namespace std;

const int Maxb = 30;
const int Maxn = 300005;

struct trie {
	int cnt;
	trie *ch[2];
	trie() { cnt = 0; ch[0] = ch[1] = NULL; }
};

int n;
int A[Maxn];
int P[Maxn];
trie *tr;

void Insert(trie *tr, int num, int lvl)
{
	tr->cnt++;
	if (lvl < 0) return;
	int wh = bool(num & 1 << lvl);
	if (!tr->ch[wh]) tr->ch[wh] = new trie();
	Insert(tr->ch[wh], num, lvl - 1);
}

int Get(trie *tr, int num, int lvl)
{
	tr->cnt--;
	if (lvl < 0) return 0;
	int wh = bool(num & 1 << lvl);
	if (tr->ch[wh] && tr->ch[wh]->cnt > 0) return Get(tr->ch[wh], num, lvl - 1);
	else return Get(tr->ch[!wh], num, lvl - 1) | 1 << lvl;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	tr = new trie();
	for (int i = 0; i < n; i++) {
		scanf("%d", &P[i]);
		Insert(tr, P[i], Maxb - 1);
	}
	for (int i = 0; i < n; i++) {
		int res = Get(tr, A[i], Maxb - 1);
		printf("%d%c", res, i + 1 < n? ' ': '\n');
	}
	return 0;
}