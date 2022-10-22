#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxb = 30;

struct trie {
	trie *ch[2];
	int cnt;
	trie() { ch[0] = ch[1] = NULL; cnt = 0; }
};

int n;
int a[Maxn];
int mask;
ll res;

void Update(trie *tr, int lvl, int val, int add)
{
	tr->cnt += add;
	if (lvl < 0) return;
	int ind = bool(val & 1 << lvl);
	if (!tr->ch[ind]) tr->ch[ind] = new trie();
	Update(tr->ch[ind], lvl - 1, val, add);
}

int getMin(trie *tr, int lvl, int mask)
{
	if (lvl < 0) return 0;
	int ind = bool(mask & 1 << lvl);
	if (tr->ch[ind] && tr->ch[ind]->cnt > 0) return getMin(tr->ch[ind], lvl - 1, mask);
	return getMin(tr->ch[!ind], lvl - 1, mask) | 1 << lvl;
}

void Union(trie *tr1, trie *tr2)
{
	if (tr2->ch[0]) if (tr1->ch[0]) Union(tr1->ch[0], tr2->ch[0]);
					else tr1->ch[0] = tr2->ch[0];
	if (tr2->ch[1]) if (tr1->ch[1]) Union(tr1->ch[1], tr2->ch[1]);
					else tr1->ch[1] = tr2->ch[1];
}

void Solve(trie *tr, int cur, int lvl, vector <int> *&V, trie *&restr)
{
	if (lvl < 0) { 
		V = new vector <int>(), restr = new trie(); 
		Update(restr, Maxb - 1, cur, 1);
		for (int i = 0; i < tr->cnt; i++)
			V->push_back(cur);
	}
	else if (!tr->ch[0]) Solve(tr->ch[1], (cur | 1 << lvl), lvl - 1, V, restr);
	else if (!tr->ch[1]) Solve(tr->ch[0], cur, lvl - 1, V, restr);
	else {
		vector <int> *A, *B;
		trie *atr, *btr;
		Solve(tr->ch[0], cur, lvl - 1, A, atr);
		Solve(tr->ch[1], (cur | 1 << lvl), lvl - 1, B, btr);
		if (A->size() < B->size()) { swap(A, B); swap(atr, btr); }
		int cand = 1 << Maxb;
		for (int i = 0; i < B->size(); i++)
			cand = min(cand, getMin(atr, Maxb - 1, (*B)[i]));
		res += cand;
		for (int i = 0; i < B->size(); i++)
			A->push_back((*B)[i]);
		Union(atr, btr);
		V = A, restr = atr;
		delete B;
	}
}

int main()
{
	trie *tr = new trie();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		Update(tr, Maxb - 1, a[i], 1);
	}
	vector <int> *dum1;
	trie *dum2;
	Solve(tr, 0, Maxb - 1, dum1, dum2);
	printf("%I64d\n", res);
	return 0;
}