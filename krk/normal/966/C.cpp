#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 61;

struct trie {
	int cnt;
	trie *ch[2];
	trie() {
		cnt = 0;
		ch[0] = ch[1] = nullptr;
	}
};

trie *tr;
int n;
vector <ll> res;

void Insert(trie *tr, ll x, int lvl, int delt)
{
	tr->cnt += delt;
	if (lvl < 0) return;
	int b = bool(x & 1ll << ll(lvl));
	if (!tr->ch[b]) tr->ch[b] = new trie();
	Insert(tr->ch[b], x, lvl - 1, delt);
}

ll getSim(trie *tr, ll x, int lvl)
{
	if (lvl < 0) return 0;
	int b = bool(x & 1ll << ll(lvl));
	if (tr->ch[b] && tr->ch[b]->cnt > 0) return getSim(tr->ch[b], x, lvl - 1) | ll(b) << ll(lvl);
	b = 1 - b;
	return (getSim(tr->ch[b], x, lvl - 1) | ll(b) << ll(lvl));
}

bool Get(trie *tr, ll x, int lvl, ll &res)
{
	if (lvl < 0) return false;
	if (tr->ch[0] && Get(tr->ch[0], x, lvl - 1, res)) return true;
	if (!bool(x & 1ll << ll(lvl)) && tr->ch[1] && tr->ch[1]->cnt > 0) {
		res = 1ll << ll(lvl);
		res |= getSim(tr->ch[1], x, lvl - 1);
		return true;
	}
	return false;
}

int main()
{
	tr = new trie();
	scanf("%d", &n);
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		ll a; scanf("%I64d", &a);
		Insert(tr, a, Maxb - 1, 1);
	}
	for (int i = 0; i < n; i++) {
		ll a = 0;
		if (!Get(tr, cur, Maxb - 1, a)) { printf("No\n"); return 0; }
		Insert(tr, a, Maxb - 1, -1);
		cur ^= a; res.push_back(a);
	}
	printf("Yes\n");
	for (int i = 0; i < res.size(); i++)
		printf("%I64d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}