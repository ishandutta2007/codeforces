#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxl = 26;

struct trie {
	trie *ch[Maxl];
	bool has;
	trie() { for (int i = 0; i < Maxl; i++) ch[i] = nullptr; has = false; }
};

char tmp[Maxn];
int n;
string s;
int cur;
multiset <int> S[Maxn];
ll res;

int Join(int a, int b)
{
	if (S[a].size() < S[b].size()) swap(a, b);
	for (multiset <int>::iterator it = S[b].begin(); it != S[b].end(); it++)
		S[a].insert(*it);
	return a;
}

trie *tr;

void Add(trie *tr, int lvl)
{
	if (lvl >= s.length()) tr->has = true;
	else {
		int let = s[lvl] - 'a';
		if (!tr->ch[let]) tr->ch[let] = new trie();
		Add(tr->ch[let], lvl + 1);
	}
}

int Solve(trie *tr, int lvl)
{
	int my = cur++;
	if (tr->has) S[my].insert(lvl);
	for (int i = 0; i < Maxl; i++)
		if (tr->ch[i]) {
			int got = Solve(tr->ch[i], lvl + 1);
			my = Join(my, got);
		}
	if (!tr->has && lvl > 0) {
		multiset <int>::iterator it = S[my].end(); it--;
		S[my].erase(it); S[my].insert(lvl);
	}
	return my;
}

int main()
{
	tr = new trie();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp); s = tmp;
		Add(tr, 0);
	}
	int ind = Solve(tr, 0);
	for (multiset <int>::iterator it = S[ind].begin(); it != S[ind].end(); it++)
		res += *it;
	cout << res << endl;
	return 0;
}