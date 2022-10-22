#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxb = 22;
const int Maxn = 500005;
const int Maxl = 12500000;

struct trie {
	int mx;
	int ch[2];
	trie() { mx = 0; ch[0] = ch[1] = 0; }
};

trie T[Maxl];
int tlen;

int newTrie() { return tlen++; }

struct DS {
	int siz, mask;
	int tr;
	DS() { siz = 0; mask = 0; tr = newTrie(); }
};

int n;
vector <ii> neigh[Maxn];
DS myds[Maxn];
int res[Maxn];

void resolveMask(int A, int mask, int lvl)
{
    if (lvl < 0) return;
    if (mask & 1 << lvl)
        swap(T[A].ch[0], T[A].ch[1]);
    for (int i = 0; i <= 1; i++) if (T[A].ch[i])
        resolveMask(T[A].ch[i], mask, lvl - 1);
}

void Merge(int A, int B, int mask, int lvl)
{
    T[A].mx = max(T[A].mx, T[B].mx);
	if (lvl < 0) return;
	int el = bool(mask & 1 << lvl);
	for (int i = 0; i <= 1; i++)
		if (T[B].ch[i]) {
			int r = (i ^ el);
			if (!T[A].ch[r]) {
                T[A].ch[r] = T[B].ch[i];
                resolveMask(T[A].ch[r], mask, lvl - 1);
			} else Merge(T[A].ch[r], T[B].ch[i], mask, lvl - 1);
		}
}

void Merge(DS &A, DS &B)
{
	A.siz += B.siz;
	int cur = (A.mask ^ B.mask);
	Merge(A.tr, B.tr, cur, Maxb - 1);
}

int getBest(int A, int B, int usd, int mask, int lvl)
{
	if (lvl < 0) return T[A].mx + T[B].mx;
	int best = 0;
	int el = bool(mask & 1 << lvl);
	for (int i = 0; i <= 1; i++)
		if (T[B].ch[i]) {
			int r = (i ^ el);
			if (T[A].ch[r]) best = max(best, getBest(T[A].ch[r], T[B].ch[i], usd, mask, lvl - 1));
			if (usd == 0) {
				r = 1 - r;
				if (T[A].ch[r]) best = max(best, getBest(T[A].ch[r], T[B].ch[i], 1, mask, lvl - 1));
			}
		}
	return best;
}

int getBest(DS &A, DS &B)
{
	return getBest(A.tr, B.tr, 0, (A.mask ^ B.mask), Maxb - 1);
}

void Add(int tr, int L, int mask, int lvl)
{
	if (lvl < 0) { T[tr].mx = max(T[tr].mx, L); return; }
	int r = bool(mask & 1 << lvl);
	if (!T[tr].ch[r]) T[tr].ch[r] = newTrie();
	Add(T[tr].ch[r], L, mask, lvl - 1);
}

void Add(DS &A, int L)
{
	A.siz++;
	Add(A.tr, L, A.mask, Maxb - 1);
}

void Traverse(int v, int lvl)
{
    Add(myds[v], lvl);
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		Traverse(u.first, lvl + 1);
		res[v] = max(res[v], res[u.first]);
		myds[u.first].mask ^= 1 << u.second;
		if (myds[v].siz < myds[u.first].siz)
		    swap(myds[v], myds[u.first]);
		res[v] = max(res[v], getBest(myds[v], myds[u.first]) - 2 * lvl);
		Merge(myds[v], myds[u.first]);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p; char ch;
		scanf("%d %c", &p, &ch);
		neigh[p].push_back(ii(i, ch - 'a'));
	}
	newTrie();
    Traverse(1, 0);
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}